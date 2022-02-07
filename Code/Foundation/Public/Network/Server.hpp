// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Copyright (C) 2018-2021 by Agustin Alvarez. All rights reserved.
//
// This work is licensed under the terms of the Apache 2.0 license.
//
// For a copy, see <https://github.com/Wolftein/Aurora.Network/blob/main/LICENSE>.
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#pragma once

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [  HEADER  ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include "Reader.hpp"
#include "Writer.hpp"

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

namespace Aurora::Network
{
    // -=(Undocumented)=-
    class Server
    {
    public:

        // -=(Undocumented)=-
        using OnAttach  = Method<void(UInt32 Session, CStr8 Address)>;

        // -=(Undocumented)=-
        using OnDetach  = Method<void(UInt32 Session)>;

        // -=(Undocumented)=-
        using OnForward = Method<void(UInt32 Session, Reader & Message)>;

        // -=(Undocumented)=-
        using OnReceive = Method<void(UInt32 Session, Reader & Message)>;

    public:

        // -=(Undocumented)=-
        static SPtr<Server> Create();

    public:

        // -=(Undocumented)=-
        virtual ~Server() = default;

        // -=(Undocumented)=-
        virtual void Poll() = 0;

        // -=(Undocumented)=-
        virtual void Attach(OnAttach OnAttach, OnDetach OnDetach, OnForward OnForward, OnReceive OnReceive) = 0;

        // -=(Undocumented)=-
        virtual void Listen(UInt32 Capacity, CStr8 Address, CStr8 Service) = 0;

        // -=(Undocumented)=-
        virtual void Close() = 0;

        // -=(Undocumented)=-
        virtual void Kick(UInt32 ID, Bool Force) = 0;

        // -=(Undocumented)=-
        virtual void Send(UInt32 ID, Bool Urgent, Writer & Message) = 0;

        // -=(Undocumented)=-
        virtual void Broadcast(CPtr<UInt32> Group, Bool Urgent, Writer & Message) = 0;

        // -=(Undocumented)=-
        virtual void Flush() = 0;

        // -=(Undocumented)=-
        virtual void Flush(UInt32 ID) = 0;
    };
}