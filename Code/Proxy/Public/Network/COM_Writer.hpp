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

#include "Core/Proxy.hpp"
#include <Network/Writer.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace Proxy
{
    [object, uuid("805B1811-A6F9-440D-AD78-6E0FF100D854"), pointer_default(unique)]
    __interface Writer_
    {
        HRESULT Clear();

        HRESULT GetData([in, satype(vbInt8)] SAFEARRAY ** Result);

        HRESULT GetCapacity([out, retval] vbInt32 * Result);

        HRESULT GetOffset([out, retval] vbInt32 * Result);

        HRESULT GetAvailable([out, retval] vbInt32 * Result);

        [local] HRESULT Write([in] vbAny Address, [in] vbInt32 Length);

        HRESULT WriteBool([in] vbBool Value);

        HRESULT WriteInt([in] vbInt32 Value);

        HRESULT WriteInt8([in] vbInt8 Value);

        HRESULT WriteInt16([in] vbInt16 Value);

        HRESULT WriteInt32([in] vbInt32 Value);

        HRESULT WriteInt64([in] vbInt64 Value);

        HRESULT WriteReal32([in] vbReal32 Value);

        HRESULT WriteReal64([in] vbReal64 Value);

        HRESULT WriteString8([in] vbStr16 Value);

        HRESULT WriteString16([in] vbStr16 Value);

        HRESULT WriteSafeArrayInt8([in, satype(vbInt8)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayInt16([in, satype(vbInt16)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayInt32([in, satype(vbInt32)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayInt64([in, satype(vbInt64)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayReal32([in, satype(vbReal32)] SAFEARRAY ** Value);

        HRESULT WriteSafeArrayReal64([in, satype(vbReal64)] SAFEARRAY ** Value);
    };

    [coclass, uuid("25DEA4F0-4C5B-4674-B357-2C6FFE8ABF46")]
    class ATL_NO_VTABLE Writer : public Writer_
    {
    public:

        // \inheritDoc
        HRESULT FinalConstruct();

        // \inheritDoc
        HRESULT FinalRelease();

        // \inheritDoc
        HRESULT Clear();

        // \inheritDoc
        HRESULT GetData(SAFEARRAY ** Result);

        // \inheritDoc
        HRESULT GetCapacity(vbInt32 * Result);

        // \inheritDoc
        HRESULT GetOffset(vbInt32 * Result);

        // \inheritDoc
        HRESULT GetAvailable(vbInt32 * Result);

        // \inheritDoc
        HRESULT Write(vbAny Address, vbInt32 Length);

        // \inheritDoc
        HRESULT WriteBool(vbBool Value);

        // \inheritDoc
        HRESULT WriteInt(vbInt32 Value);

        // \inheritDoc
        HRESULT WriteInt8(vbInt8 Value);

        // \inheritDoc
        HRESULT WriteInt16(vbInt16 Value);

        // \inheritDoc
        HRESULT WriteInt32(vbInt32 Value);

        // \inheritDoc
        HRESULT WriteInt64(vbInt64 Value);

        // \inheritDoc
        HRESULT WriteReal32(vbReal32 Value);

        // \inheritDoc
        HRESULT WriteReal64(vbReal64 Value);

        // \inheritDoc
        HRESULT WriteString8(vbStr16 Value);

        // \inheritDoc
        HRESULT WriteString16(vbStr16 Value);

        // \inheritDoc
        HRESULT WriteSafeArrayInt8(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT WriteSafeArrayInt16(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT WriteSafeArrayInt32(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT WriteSafeArrayInt64(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT WriteSafeArrayReal32(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT WriteSafeArrayReal64(SAFEARRAY ** Value);

    private:

        // -=(Undocumented)=-
        HRESULT WriteSafeArray(SAFEARRAY * Value);

    public:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        Aurora::Network::Writer mWrapper;
    };
}