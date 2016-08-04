#ifndef LOCAL_PLANNER_NULL_H
#define LOCAL_PLANNER_NULL_H

/// PROJECT
#include <path_follower/local_planner/local_planner.h>

class LocalPlannerNull : public LocalPlanner
{
public:
    LocalPlannerNull(PathFollower& controller,
                     tf::Transformer &transformer);

    virtual void setGlobalPath(Path::Ptr path) override;

    virtual Path::Ptr updateLocalPath(const std::vector<Constraint::Ptr>& constraints,
                                      const std::vector<Scorer::Ptr>& scorer,
                                      const std::vector<bool>& fconstraints,
                                      const std::vector<double>& wscorer,
                                      Path::Ptr& wlp) override;
    virtual bool isNull() const override;
    virtual void setParams(int nnodes, double dis2p, double dis2o, double s_angle) override;
    virtual void setVelocity(geometry_msgs::Twist::_linear_type vector) override;
    virtual void setVelocity(double velocity) override;
};

#endif // LOCAL_PLANNER_NULL_H
