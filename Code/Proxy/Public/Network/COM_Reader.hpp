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

#include "Core/Proxy.hpp"
#include <Network/Reader.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

inline namespace Proxy
{
    [object, uuid("57836433-999F-478F-A8D9-2E5A61CB9D78"), pointer_default(unique)]
    __interface Reader_
    {
        HRESULT SetData([in, satype(vbInt8)] SAFEARRAY ** Result);

        HRESULT GetData([in, satype(vbInt8)] SAFEARRAY ** Result);

        HRESULT GetCapacity([out, retval] vbInt32 * Result);

        HRESULT GetOffset([out, retval] vbInt32 * Result);

        HRESULT GetAvailable([out, retval] vbInt32 * Result);

        HRESULT Skip([in] vbInt32 Length);

        [local] HRESULT Read([in] vbAny Address, [in] vbInt32 Length);

        HRESULT ReadBool([out, retval] vbBool * Result);

        HRESULT ReadInt([out, retval] vbInt32 * Result);

        HRESULT ReadInt8([out, retval] vbInt8 * Result);

        HRESULT ReadInt16([out, retval] vbInt16 * Result);

        HRESULT ReadInt32([out, retval] vbInt32 * Result);

        HRESULT ReadInt64([out, retval] vbInt64 * Result);

        HRESULT ReadReal32([out, retval] vbReal32 * Result);

        HRESULT ReadReal64([out, retval] vbReal64 * Result);

        HRESULT ReadString8([out, retval] vbStr16 * Result);

        HRESULT ReadString16([out, retval] vbStr16 * Result);

        HRESULT ReadSafeArrayInt8([in, satype(vbInt8)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayInt16([in, satype(vbInt16)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayInt32([in, satype(vbInt32)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayInt64([in, satype(vbInt64)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayReal32([in, satype(vbReal32)] SAFEARRAY ** Value);

        HRESULT ReadSafeArrayReal64([in, satype(vbReal64)] SAFEARRAY ** Value);
    };

    [coclass, uuid("9BE50AF2-385F-4C56-9826-65C320451642")]
    class ATL_NO_VTABLE Reader : public Reader_
    {
    public:

        // \inheritDoc
        HRESULT FinalConstruct();

        // \inheritDoc
        HRESULT FinalRelease();

        // \inheritDoc
        HRESULT SetData(SAFEARRAY ** Result);

        // \inheritDoc
        HRESULT GetData(SAFEARRAY ** Result);

        // \inheritDoc
        HRESULT GetCapacity(vbInt32 * Result);

        // \inheritDoc
        HRESULT GetOffset(vbInt32 * Result);

        // \inheritDoc
        HRESULT GetAvailable(vbInt32 * Result);

        // \inheritDoc
        HRESULT Skip(vbInt32 Length);

        // \inheritDoc
        HRESULT Read(vbAny Address, vbInt32 Length);

        // \inheritDoc
        HRESULT ReadBool(vbBool * Result);

        // \inheritDoc
        HRESULT ReadInt(vbInt32 * Result);

        // \inheritDoc
        HRESULT ReadInt8(vbInt8 * Result);

        // \inheritDoc
        HRESULT ReadInt16(vbInt16 * Result);

        // \inheritDoc
        HRESULT ReadInt32(vbInt32 * Result);

        // \inheritDoc
        HRESULT ReadInt64(vbInt64 * Result);

        // \inheritDoc
        HRESULT ReadReal32(vbReal32 * Result);

        // \inheritDoc
        HRESULT ReadReal64(vbReal64 * Result);

        // \inheritDoc
        HRESULT ReadString8(vbStr16 * Result);

        // \inheritDoc
        HRESULT ReadString16(vbStr16 * Result);

        // \inheritDoc
        HRESULT ReadSafeArrayInt8(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT ReadSafeArrayInt16(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT ReadSafeArrayInt32(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT ReadSafeArrayInt64(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT ReadSafeArrayReal32(SAFEARRAY ** Value);

        // \inheritDoc
        HRESULT ReadSafeArrayReal64(SAFEARRAY ** Value);

    private:

        // -=(Undocumented)=-
        HRESULT ReadSafeArray(SAFEARRAY ** Value, VARTYPE Type, UInt32 Element);

    public:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        Aurora::Network::Reader mWrapper;
    };
}