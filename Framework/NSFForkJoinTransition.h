// Copyright 2004-2016, North State Software, LLC.  All rights reserved.

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

#ifndef NSF_FORK_JOIN_TRANSITION_H
#define NSF_FORK_JOIN_TRANSITION_H

#include "NSFExternalTransition.h"
#include "NSFForkJoin.h"

namespace NorthStateFramework
{
    /// <summary>
    /// Represents a transition between two fork-joins.
    /// </summary>
    /// <remarks>
    /// This class is an extension to UML 2.x.  It allows a transition to be made between two fork-joins,
    /// optionally specifying a region associated with the transition.  If a region is specified, its
    /// active substate will be the target fork-join after the transition is taken.  If a NULL region is
    /// specified, then no region's active substate will be the target fork-join as a result of taking 
    /// this transition.  This latter case, where the associated region is NULL, is equivalent to using
    /// an external transition between the two fork-joins.
    /// </remarks>
    class NSFForkJoinTransition : public NSFExternalTransition
    {
    public:

        friend class NSFForkJoin;

        /// <summary>
        /// Creates a transition between two fork-joins.
        /// </summary>
        /// <param name="name">User assigned name for transition.</param>
        /// <param name="source">Transition source.</param>
        /// <param name="target">Transition target.</param>
        /// <param name="region">Transition region.</param>
        /// <param name="action">Transition action.</param>
        /// <remarks>
        /// This class is an extension to UML 2.x.  It allows a transition to be made between two fork-joins,
        /// optionally specifying a region associated with the transition.  If a region is specified, its
        /// active substate will be the target fork-join after the transition is taken.  If a NULL region is
        /// specified, then no region's active substate will be the target fork-join as a result of taking 
        /// this transition.  This latter case, where the associated region is NULL, is equivalent to using
        /// an external transition between the two fork-joins.
        /// </remarks>
        NSFForkJoinTransition(const NSFString& name, NSFForkJoin* source, NSFForkJoin* target, NSFRegion* region, const NSFVoidAction<NSFStateMachineContext>& action);

        /// <summary>
        /// Creates a transition between two fork-joins.
        /// </summary>
        /// <param name="name">User assigned name for transition.</param>
        /// <param name="source">Transition source.</param>
        /// <param name="target">Transition target.</param>
        /// <param name="region">Transition region.</param>
        /// <param name="action">Transition action.</param>
        /// <remarks>
        /// This class is an extension to UML 2.x.  It allows a transition to be made between two fork-joins,
        /// optionally specifying a region associated with the transition.  If a region is specified, its
        /// active substate will be the target fork-join after the transition is taken.  If a NULL region is
        /// specified, then no region's active substate will be the target fork-join as a result of taking 
        /// this transition.  This latter case, where the associated region is NULL, is equivalent to using
        /// an external transition between the two fork-joins.
        /// </remarks>
        NSFForkJoinTransition(const NSFString& name, NSFForkJoin* source, NSFForkJoin* target, NSFRegion* region, const NSFVoidAction<NSFStateMachineContext>* action);

    private:

        NSFRegion* forkJoinRegion;

        NSFRegion* getForkJoinRegion() const { return forkJoinRegion; }
    };
}

#endif // NSF_FORK_JOIN_TRANSITION_H
