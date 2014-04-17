

#ifndef TM_SPEED_FIRST_TEAM_B_DEADLINE_ESTIMATOR
#define TM_SPEED_FIRST_TEAM_B_DEADLINE_ESTIMATOR

#include "TM_SpeedFirstDeadlineEstimator.h"

class TM_SpeedFirstTeamBDeadlineEstimator : public TM_SpeedFirstDeadlineEstimator {
public:

	int calcWorkingTime(int difficulty);
	int calcWorkingSpeed(int difficulty);
	int calcRequiredWorkingDays(int difficulty);
};


#endif
