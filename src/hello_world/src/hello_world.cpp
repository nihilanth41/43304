#include <ros/ros.h>

int main(int argc, char **argv) { 
	ros::init(argc, argv, "hello_world");
	ros::NodeHandle nh;
	ros::Rate r(1);
	while(ros::ok()) {
		ros::spinOnce;
		ROS_INFO_STREAM("Hello, World!");
	}

	return 0;
}
