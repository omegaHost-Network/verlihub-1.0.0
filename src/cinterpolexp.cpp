/*
	Copyright (C) 2003-2005 Daniel Muller, dan at verliba dot cz
	Copyright (C) 2006-2014 Verlihub Project, devs at verlihub-project dot org

	Verlihub is free software; You can redistribute it
	and modify it under the terms of the GNU General
	Public License as published by the Free Software
	Foundation, either version 3 of the license, or at
	your option any later version.

	Verlihub is distributed in the hope that it will be
	useful, but without any warranty, without even the
	implied warranty of merchantability or fitness for
	a particular purpose. See the GNU General Public
	License for more details.

	Please see http://www.gnu.org/licenses/ for a copy
	of the GNU General Public License.
*/

#include "cinterpolexp.h"
#include <iostream>

using namespace std;
namespace nVerliHub {
	namespace nUtils {

cInterpolExp::cInterpolExp(unsigned int &var, long toval, int togo, int skip):
	mVariable(var),
	mTargetValue(toval),
	mStepsToGo(togo),
	mSkipSteps(skip)
{
	cout << " constructor " << endl;
	mInitValue = mVariable;
	mCurrentValue = mInitValue;
	mNextStep = (mTargetValue - mInitValue) /2;
	mSkipedSteps = 0;
}


cInterpolExp::~cInterpolExp()
{
}



/*!
    \fn nUtils::cInterpolExp::step()
 */
void cInterpolExp::step()
{
	cout << " step " << mStepsToGo << "  " << mSkipedSteps << "  "  << mSkipSteps << endl;
	mStepsToGo --;
	if( ( mSkipedSteps++ ) >= mSkipSteps )
	{
		mSkipedSteps = 0;
		mVariable += mNextStep;
		cout << "step " << mNextStep << " value " << mVariable << endl;
		mNextStep /= 2;
	}
}

bool cInterpolExp::done()
{
	return ( mStepsToGo <= 0 );
}
	}; // namespace nUtils
}; // namespace nVerliHub
