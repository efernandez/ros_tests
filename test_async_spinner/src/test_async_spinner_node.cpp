
#include <ros/callback_queue.h>
#include <ros/ros.h>
#include <ros/subscribe_options.h>
#include <std_msgs/Int32.h>

class Node
{
public:
  Node()
    : nh_()
    , callback_queue_()
    , spinner_(1, &callback_queue_)
    , light_sub_(nh_.subscribe("light", 1, &Node::lightCallback, this))
    , sum_(0.0)
  {
    // Note that nh_.subscribe doesn't see the output of ros::SubscribeOptions::create as a ros::SubscribeOptions
    // object if we do
    //
    //   nh_.subscribe(ros::SubscribeOptions::create<std_msgs::Int32>(...))
    //
    // it fails to compile, so we need to do it this way (which cannot be used in the initialization list unless we
    // have an attribute for the ros::SubscribeOptions):
    ros::SubscribeOptions ops = ros::SubscribeOptions::create<std_msgs::Int32>(
        "heavy", 1, boost::bind(&Node::heavyCallback, this, _1), ros::VoidConstPtr(), &callback_queue_);
    heavy_sub_ = nh_.subscribe(ops);

    spinner_.start();
  }

private:
  void lightCallback(const std_msgs::Int32ConstPtr& msg)
  {
    ROS_INFO_STREAM(__PRETTY_FUNCTION__ << " received message " << *msg);
  }

  void heavyCallback(const std_msgs::Int32ConstPtr& msg)
  {
    ROS_INFO_STREAM(__PRETTY_FUNCTION__ << " received message " << *msg);

    sum_ = 0.0;
    for (int i = 0; i < msg->data; ++i)
    {
      sum_ += std::pow(i, 3.0);
    }

    ROS_INFO_STREAM(__PRETTY_FUNCTION__ << " DONE (sum = " << sum_ << ")");
  }

  ros::NodeHandle nh_;
  ros::CallbackQueue callback_queue_;
  ros::AsyncSpinner spinner_;
  ros::Subscriber light_sub_;
  ros::Subscriber heavy_sub_;

  double sum_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "test_async_spinner_node");

  Node node;

  ros::spin();

  return EXIT_SUCCESS;
}
