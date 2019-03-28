#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "pimouse_tf_broadcaster");
  ros::NodeHandle n;

  ros::Rate rate(10.0);

  tf::TransformBroadcaster br;
  tf::Transform tf_urg;   //transform of urg
  tf::Transform tf_rs; 	  //transform of realsense

  tf_urg.setOrigin( tf::Vector3(0.0, 0.0, 0.10315) );
  tf_urg.setRotation( tf::Quaternion(0, 0, 0, 1) );

  tf_rs.setOrigin( tf::Vector3(0.05, 0.0, 0.2) );
  tf_rs.setRotation( tf::Quaternion(0, 0, 0, 1) );

  while(n.ok()){
    br.sendTransform(
      tf::StampedTransform(
        tf_urg,
        ros::Time::now(),
	"base_link",
	"base_laser"));

    br.sendTransform(
      tf::StampedTransform(
        tf_rs, 
	ros::Time::now(),
	"base_link",
	"base_camera"));

    rate.sleep();
  }
  return 0;
}
