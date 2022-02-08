// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Copyright (C) 2018-2022 by Agustin Alvarez. All rights reserved.
//
// This work is licensed under the terms of the Apache 2.0 license.
//
// For a copy, see <https://github.com/Wolftein/Aurora.Network/blob/main/LICENSE>.
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#pragma once

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [  HEADER  ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include "COM_Group.hpp"
#include "COM_Reader.hpp"
#include "COM_Writer.hpp"
#include "COM_Statistics.hpp"
#include <Network/Server.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace Proxy
{
    [object, uuid("6A4DDF54-09D3-494D-8988-C37B914D398A"), pointer_default(unique)]
    __interface Server_
    {
        HRESULT Poll();

        HRESULT Attach([in] vbInt32 OnAttach, [in] vbInt32 OnDetach, [in] vbInt32 OnForward, [in] vbInt32 OnReceive);

        HRESULT Listen([in] vbInt32 Capacity, [in] vbStr8 Address, [in] vbStr8 Service);

        HRESULT Close();

        HRESULT Kick([in] vbInt32 Session, [in] vbBool Force);

        HRESULT Send([in] vbInt32 Session, [in] vbBool Urgent, [in] Writer_ * Message);

        HRESULT Broadcast([in] Group_ * Set, [in] vbBool Urgent, [in] Writer_ * Message);

        HRESULT Flush([in, defaultvalue(0)] vbInt32 Session);

        HRESULT GetStatistics([in] vbInt32 Session, [out, retval] Statistics * Result);
    };

    [coclass, uuid("AC398261-6275-4797-950A-5B914DDB2130")]
    class ATL_NO_VTABLE Server : public Server_
    {
    public:

        // \inheritDoc
        HRESULT FinalConstruct();

        // \inheritDoc
        HRESULT FinalRelease();

        // \inheritDoc
        HRESULT Poll();

        // \inheritDoc
        HRESULT Attach(vbInt32 OnAttach, vbInt32 OnDetach, vbInt32 OnForward, vbInt32 OnReceive);

        // \inheritDoc
        HRESULT Listen(vbInt32 Capacity, vbStr8 Address, vbStr8 Service);

        // \inheritDoc
        HRESULT Close();

        // \inheritDoc
        HRESULT Kick(vbInt32 Session, vbBool Force);

        // \inheritDoc
        HRESULT Send(vbInt32 Session, vbBool Urgent, Writer_ * Message);

        // \inheritDoc
        HRESULT Broadcast(Group_ * Set, vbBool Urgent, Writer_ * Message);

        // \inheritDoc
        HRESULT Flush(vbInt32 Session);

        // \inheritDoc
        HRESULT GetStatistics(vbInt32 Session, Statistics * Result);

    public:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        SPtr<Aurora::Network::Server> mWrapper;
    };
}