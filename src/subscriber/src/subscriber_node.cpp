#include <ros/ros.h>
#include "std_msgs/Int8.h"

#define QUEUE_SIZE 8

//void sub_callback(const std_msgs::String &msg) {
//	// Print the message
//	ROS_INFO_STREAM("Recieved message: " << msg.data << "");
//}
void sub_callback(const std_msgs::Int8 &msg) {
	ROS_INFO("%d", msg.data);
}

int main(int argc, char **argv) { 
	ros::init(argc, argv, "subscriber_node");
	ros::NodeHandle nh;
	ros::Subscriber sub=nh.subscribe("lab4_topic", QUEUE_SIZE, &sub_callback);

	ros::Rate rate(4); // 4 Hz
	while(ros::ok()) {
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}
