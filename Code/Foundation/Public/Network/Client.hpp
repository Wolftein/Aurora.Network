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
    class Client
    {
    public:

        // -=(Undocumented)=-
        using OnAttach  = Method<void()>;

        // -=(Undocumented)=-
        using OnDetach  = Method<void(SInt32 Code)>;

        // -=(Undocumented)=-
        using OnForward = Method<void(Reader & Message)>;

        // -=(Undocumented)=-
        using OnReceive = Method<void(Reader & Message)>;

    public:

        // -=(Undocumented)=-
        static SPtr<Client> Create();

    public:

        // -=(Undocumented)=-
        virtual ~Client() = default;

        // -=(Undocumented)=-
        virtual void Poll() = 0;

        // -=(Undocumented)=-
        virtual void Attach(OnAttach OnAttach, OnDetach OnDetach, OnForward OnForward, OnReceive OnReceive) = 0;

        // -=(Undocumented)=-
        virtual void Connect(CStr8 Address, CStr8 Service) = 0;

        // -=(Undocumented)=-
        virtual void Close(Bool Force) = 0;

        // -=(Undocumented)=-
        virtual void Send(Bool Urgent, Writer & Message) = 0;

        // -=(Undocumented)=-
        virtual void Flush() = 0;
    };
}