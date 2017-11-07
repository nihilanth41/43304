#include <ros/ros.h>
#include "std_msgs/Int8.h"

#define QUEUE_SIZE 8

int main(int argc, char **argv) { 
	ros::init(argc, argv, "publish_node");
	ros::NodeHandle nh;
	// Syntax is <message_type>("topic_name", queue_size);
	//ros::Publisher pub=nh.advertise<std_msgs::String>("lab4_topic", QUEUE_SIZE);
	ros::Publisher pub=nh.advertise<std_msgs::Int8>("lab4_topic", QUEUE_SIZE);
	if(!pub) {
		ROS_ERROR_STREAM("Error initializing publisher");
		return -1; 
	}


	// http://wiki.ros.org/roscpp/Overview/Time#Sleeping_and_Rates
	ros::Rate rate(1); // 1 Hz

	//static int x = 0;
	std_msgs::Int8 x; 
	x.data = 0;
	//std_msgs::String str;
	//str.data = "Hello from publisher";

	while(ros::ok()) {
		/* Increment a counter just so we can identify messages uniquely and see if any get lost etc. */
		/* How to format this into String? Or should not even bother and just use a different messsage type instead? */
		/* Similarly, if we use a different message type, do we need to specify a different topic? */
		/* Can we have multiple message types in a single topic? */
		x.data++;
		ROS_DEBUG_STREAM("Publishing message");
		pub.publish(x);
		rate.sleep();
	}
	return 0;
}
