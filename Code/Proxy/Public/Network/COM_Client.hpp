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

#include "COM_Reader.hpp"
#include "COM_Writer.hpp"
#include <Network/Client.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace Proxy
{
    [object, uuid("6EE11DB6-EE21-4134-841F-27B1BC35B1C9"), pointer_default(unique)]
    __interface Client_
    {
        HRESULT Poll();

        HRESULT Attach([in] vbInt32 OnAttach, [in] vbInt32 OnDetach, [in] vbInt32 OnForward, [in] vbInt32 OnReceive);

        HRESULT Connect([in] vbStr8 Address, [in] vbStr8 Service);

        HRESULT Close([in] vbBool Force);

        HRESULT Send([in] vbBool Urgent, [in] Writer_ * Message);

        HRESULT Flush();
    };

    [coclass, uuid("07CC11E3-D300-4CD4-9EB0-C4EB4D63865D")]
    class ATL_NO_VTABLE Client : public Client_
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
        HRESULT Connect(vbStr8 Address, vbStr8 Service);

        // \inheritDoc
        HRESULT Close(vbBool Force);

        // \inheritDoc
        HRESULT Send(vbBool Urgent, Writer_ * Message);

        // \inheritDoc
        HRESULT Flush();

    public:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        SPtr<Aurora::Network::Client> mWrapper;
    };
}