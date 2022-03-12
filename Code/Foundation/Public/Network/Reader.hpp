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

#include "Core/Core.hpp"

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

namespace Aurora::Network
{
    // -=(Undocumented)=-
    class Reader final
    {
    public:

        // -=(Undocumented)=-
        explicit Reader(CPtr<UInt08> Memory = CPtr<UInt08>())
            : mBuffer { Memory.data() },
              mLength { Memory.size() },
              mOffset { 0 }
        {
        }

        // -=(Undocumented)=-
        CPtr<UInt08> GetData()
        {
            return CPtr<UInt08>(mBuffer, mLength);
        }

        // -=(Undocumented)=-
        UInt32 GetCapacity() const
        {
            return mLength;
        }

        // -=(Undocumented)=-
        UInt32 GetAvailable() const
        {
            return GetCapacity() - mOffset;
        }

        // -=(Undocumented)=-
        UInt32 GetOffset() const
        {
            return mOffset;
        }

        // -=(Undocumented)=-
        void Skip(UInt32 Length)
        {
            mOffset += (mOffset + Length <= mLength ? Length : 0);
        }

        // -=(Undocumented)=-
        template<typename Type>
        Type Peek(UInt32 Length = sizeof(Type))
        {
            if (mOffset + Length > mLength)
            {
                return {};
            }

            if constexpr (eastl::is_pointer_v<Type>)
            {
                return reinterpret_cast<Type>(mBuffer + mOffset);
            }
            else
            {
                return * reinterpret_cast<Type *>(mBuffer + mOffset);
            }
        }

        // -=(Undocumented)=-
        template<typename Type>
        Type Read(UInt32 Length = sizeof(Type))
        {
            const Type Result = Peek<Type>(Length);
            mOffset += Length;
            return Result;
        }

        // -=(Undocumented)=-
        Bool ReadBool()
        {
            return Read<Bool>();
        }

        // -=(Undocumented)=-
        template<typename Type>
        Type ReadInt()
        {
            Type   Result   = 0u;
            UInt32 Position = 0u;
            do
            {
                Result |= static_cast<Type>((Peek<UInt08>() & 0x7Fu)) << (7u * Position++);
            } while (ReadUnsignedInt8() & 0x80u && Position < 10); // 10 bytes it's the maximum allowed for 64bit numbers

            return Result;
        }

        // -=(Undocumented)=-
        SInt08 ReadInt8()
        {
            return Read<SInt08>();
        }

        // -=(Undocumented)=-
        UInt08 ReadUnsignedInt8()
        {
            return Read<UInt08>();
        }

        // -=(Undocumented)=-
        SInt16 ReadInt16()
        {
            return Read<SInt16>();
        }

        // -=(Undocumented)=-
        UInt16 ReadUnsignedInt16()
        {
            return Read<UInt16>();
        }

        // -=(Undocumented)=-
        SInt32 ReadInt32()
        {
            return Read<SInt32>();
        }

        // -=(Undocumented)=-
        UInt32 ReadUnsignedInt32()
        {
            return Read<UInt32>();
        }

        // -=(Undocumented)=-
        SInt64 ReadInt64()
        {
            return Read<SInt64>();
        }

        // -=(Undocumented)=-
        UInt64 ReadUnsignedInt64()
        {
            return Read<UInt64>();
        }

        // -=(Undocumented)=-
        Real32 ReadReal32()
        {
            return Read<Real32>();
        }

        // -=(Undocumented)=-
        Real64 ReadReal64()
        {
            return Read<Real64>();
        }

        // -=(Undocumented)=-
        CStr8 ReadString8()
        {
            const auto Size = ReadInt<UInt32>();
            const auto Data = Read<CStr8::const_pointer>(Size * sizeof(CStr8::value_type));

            return CStr8(Data, Size);
        }

        // -=(Undocumented)=-
        CStr16 ReadString16()
        {
            const auto Size = ReadInt<UInt32>();
            const auto Data = Read<CStr16::const_pointer>(Size * sizeof(CStr16::value_type));

            return CStr16(Data, Size);
        }

    private:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        UInt08 * mBuffer;
        UInt32   mLength;
        UInt32   mOffset;
    };
}