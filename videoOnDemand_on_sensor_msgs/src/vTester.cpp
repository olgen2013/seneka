/*
 * vTester.cpp
 *
 *  Created on: 23.04.2013
 *      Author: Johannes Goth (cmm-jg)
 */

#include "ros/ros.h"
#include "videoOnDemand_on_sensor_msgs/getVideo.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "vTester");

	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<videoOnDemand_on_sensor_msgs::getVideo>("seneka/VODNODE/getVideo");
	videoOnDemand_on_sensor_msgs::getVideo srv;

	ROS_INFO("Connecting to Server ...");

	// set request to 1 -> will create a video
	srv.request.creatVideo = 1;
	// connect to server
	client.call(srv);

	if((int)srv.response.releasedVideo == 1)
		ROS_INFO("Creating video ...");
	else if((int)srv.response.releasedVideo == -1)
		ROS_ERROR("Video recorder is busy !!");
	else if((int)srv.response.releasedVideo == -2)
		ROS_ERROR("NO complete video available !!");
	else
		ROS_ERROR("Connection to Server failed");
	return 0;
}
