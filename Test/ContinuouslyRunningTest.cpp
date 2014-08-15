// Copyright 2004-2014, North State Software, LLC.  All rights reserved.

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#include "ContinuouslyRunningTest.h"

using namespace NorthStateFramework;

namespace NSFTest
{
#if (defined WIN32) || (defined WINCE)
    // Using "this" in initializer as pointer to base type, disable warning as this is perfectly safe.
#pragma warning( disable : 4355 )
#endif

    //#region Constructors
    ContinuouslyRunningTest::ContinuouslyRunningTest(const NSFString& name, int myNumberOfRepeatedEvents)
        : NSFStateMachine(name, new NSFEventThread(name)), numberOfRepeatedEvents(myNumberOfRepeatedEvents), currentEventCount(1),
        // Events
        event1("Event1", this),
        event2("Event2", this),
        event3("Event3", this),
        event4("Event4", this, "EventFourData"),
        event5("Event5", this),
        event6("Event6", this),
        //States
        test2InitialState("InitialTest3", this),
        state1("State1", this, NSFAction(this, &ContinuouslyRunningTest::state1EntryAction), NSFAction(this, &ContinuouslyRunningTest::state1ExitAction)),
        state2("State2", this, NULL, NULL),
        //State 1 Region
        state1InitialState("State1Initial", &state1),
        state1History("State1History", &state1),
        state1_1("State1_1", &state1, NULL, NULL),
        state1_2("State1_2", &state1, NULL, NULL),
        // State1_2 Region
        state1_2InitialState("State1_2Initial", &state1_2),
        state1_2_1("State1_2_1", &state1_2, NULL, NULL),
        state1_2_2("State1_2_2", &state1_2, NULL, NULL),
        //Transitions
        // ContinuouslyRunningTest Region
        test1InitialToState1Transition("Test1InitialToState1", &test2InitialState, &state1, NULL, NULL, NULL),
        state1ToState2Transition("State1ToState2", &state1, &state2, &event5, NULL, NULL),
        state2ToState1Transition("State2ToState1", &state2, &state1, &event6, NULL, NULL),
        // State1 Region
        state1InitialToState1HistoryTransition("State1InitialToState1History", &state1InitialState, &state1History, NULL, NULL, NULL),
        state1HistoryToState1_1Transition("State1HistoryToState1_1", &state1History, &state1_1, NULL, NULL, NULL),
        state1_1ToState1_2Transition("State1_1ToState1_2", &state1_1, &state1_2, &event1, NULL, NULL),
        state1_2ToState1_1Transition("State1_2ToState1_1", &state1_2, &state1_1, &event2, NULL, NULL),
        // State1_2 Region
        state1_2InitialStateToState1_2_1Transition("State1_2InitialStateToState1_2_1", &state1_2InitialState, &state1_2_1, NULL, NULL, NULL),
        state1_2_1ToState1_2_2Transition("State1_2_1ToState1_2_2", &state1_2_1, &state1_2_2, &event3, NULL, NULL),
        state1_2_2ToState1_2_1Transition("State1_2_2ToState1_2_1", &state1_2_2, &state1_2_1, &event4, NULL, NULL)
    {
    }

    ContinuouslyRunningTest::~ContinuouslyRunningTest()
    {
        event2.unschedule();
        terminate(true);
        delete getEventThread();
    }

    bool ContinuouslyRunningTest::runTest(NSFString& errorMessage)
    {
        // start the state machine
        startStateMachine();

        return true;
    }

    void ContinuouslyRunningTest::state1EntryAction(const NSFStateMachineContext& context)
    {
        state1_1.EntryActions += NSFAction(this, &ContinuouslyRunningTest::state1_1EntryAction);
    }

    void ContinuouslyRunningTest::state1ExitAction(const NSFStateMachineContext& context)
    {
        state1_1.EntryActions -= NSFAction(this, &ContinuouslyRunningTest::state1_1EntryAction);
    }

    void ContinuouslyRunningTest::state1_1EntryAction(const NSFStateMachineContext& context)
    {
        ++currentEventCount;

        if ((currentEventCount % numberOfRepeatedEvents) == 0)
        {
            NSFDebugUtility::getPrimaryDebugUtility().writeToConsole(NSFString("."));
            event1.queueEvent();
            event3.queueEvent();
            event4.copy(true)->queueEvent();
            event2.schedule(50, 0);
        }
        else 
        {
            event1.queueEvent();
            event5.queueEvent();
            event6.copy(true)->queueEvent();
            event2.schedule(50, 0);
        }
    }
}
