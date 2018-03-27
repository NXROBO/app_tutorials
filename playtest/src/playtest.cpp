#include "ros/ros.h"
#include "playtest/scene.h"
#include "playtest/play.h"

class Play
{
public:
    Play(const  ros::NodeHandle &n):_nh(n)
    {
        _ss=_nh.advertiseService("playtest",&Play::call_back,this);
    }
    bool call_back(playtest::scene::Request &req, playtest::scene::Response &res)
    {
        if(req.RUN==req.type  )
        {
            ros::ServiceClient ct= _nh.serviceClient<playtest::play>("b_play");
                playtest::play srv;
                srv.request.type =0;
                srv.request.param =req.param;
                srv.request.block = 1;
                if (ct.call(srv))
                {
                    ROS_INFO("RESULT: %d", srv.response.status);
                }
                else
                {
                    ROS_ERROR("Failed to call service b_play");
                }
        }
        res.status=res.SUCCESS;
        return true;
    }
private:
    ros::ServiceServer _ss;
    ros::NodeHandle _nh;
};
int main(int argc, char **argv)
{
    ros::init(argc, argv, "playtest");
    ros::NodeHandle n;
    Play Play(n);
    ros::spin();
    return 0;
}

