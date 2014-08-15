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

#ifndef COMMAND_PROCESSOR_OBSERVER_H
#define COMMAND_PROCESSOR_OBSERVER_H

#include "CommandProcessorWithResetStateMachine.h"

namespace CommandProcessorWithResetStateMachineExample
{
    class CommandProcessorObserver
    {
    public:

        CommandProcessorObserver(CommandProcessorWithResetStateMachine& commandProcessor);
        void handleStateEntered(const NSFStateMachineContext& context);
        void handleTransition(const NSFStateMachineContext& context);
        void handleStateExited(const NSFStateMachineContext& context);
    };
}

#endif // COMMAND_PROCESSOR_OBSERVER_H