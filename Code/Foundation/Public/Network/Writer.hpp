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

#include "Core/Core.hpp"

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

namespace Aurora::Network
{
    // -=(Undocumented)=-
    class Writer final
    {
    public:

        // -=(Undocumented)=-
        static constexpr UInt32 kDefaultCapacity = 512;

    public:

        // -=(Undocumented)=-
        explicit Writer(UInt32 Capacity = kDefaultCapacity)
            : mBuffer ( Capacity ),
              mOffset { 0 }
        {
        }

        // -=(Undocumented)=-
        CPtr<UInt08> GetData()
        {
            return CPtr<UInt08>(mBuffer.data(), mOffset);
        }

        // -=(Undocumented)=-
        UInt32 GetCapacity() const
        {
            return mBuffer.size();
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
        Bool Ensure(UInt32 Length)
        {
            if (mOffset + Length >= GetCapacity())
            {
                const UInt32 Amount = (mOffset + Length - GetCapacity());
                mBuffer.resize(GetCapacity() + (Amount / kDefaultCapacity + 1) * kDefaultCapacity);
            }
            return true;
        }

        // -=(Undocumented)=-
        void Clear()
        {
            mOffset = 0u;
        }

        // -=(Undocumented)=-
        template<typename Type>
        void Write(Type Data, UInt32 Length = sizeof(Type))
        {
            if (!Ensure(Length))
            {
                return;
            }

            if constexpr (eastl::is_pointer_v<Type>)
            {
                std::memcpy(& mBuffer[mOffset], Data, Length);
            }
            else
            {
                * reinterpret_cast<Type *> (& mBuffer[mOffset]) = Data;
            }
            mOffset += Length;
        }

        // -=(Undocumented)=-
        void WriteBool(Bool Data)
        {
            Write<Bool>(Data);
        }


        // -=(Undocumented)=-
        template<typename Type>
        void WriteInt(Type Data)
        {
            for (; Data > 0x7F; Data >>= 7u)
            {
                WriteUnsignedInt8(static_cast<UInt08>(Data & 0x7Fu) | 0x80u);
            }
            WriteUnsignedInt8(static_cast<UInt08>(Data) & 0x7Fu);
        }

        // -=(Undocumented)=-
        void WriteInt8(SInt08 Data)
        {
            Write<SInt08>(Data);
        }

        // -=(Undocumented)=-
        void WriteUnsignedInt8(UInt08 Data)
        {
            Write<UInt08>(Data);
        }

        // -=(Undocumented)=-
        void WriteInt16(SInt16 Data)
        {
            Write<SInt16>(Data);
        }

        // -=(Undocumented)=-
        void WriteUnsignedInt16(UInt16 Data)
        {
            Write<UInt16>(Data);
        }

        // -=(Undocumented)=-
        void WriteInt32(SInt32 Data)
        {
            Write<SInt32>(Data);
        }

        // -=(Undocumented)=-
        void WriteUnsignedInt32(UInt32 Data)
        {
            Write<UInt32>(Data);
        }

        // -=(Undocumented)=-
        void WriteInt64(SInt64 Data)
        {
            Write<SInt64>(Data);
        }

        // -=(Undocumented)=-
        void WriteUnsignedInt64(UInt64 Data)
        {
            Write<UInt64>(Data);
        }

        // -=(Undocumented)=-
        void WriteReal32(Real32 Data)
        {
            Write<Real32>(Data);
        }

        // -=(Undocumented)=-
        void WriteReal64(Real64 Data)
        {
            Write<Real64>(Data);
        }

        // -=(Undocumented)=-
        void WriteString8(CStr8 Data)
        {
            WriteInt(Data.size());

            if (!Data.empty())
            {
                Write<CStr8::const_pointer>(Data.data(), Data.size() * sizeof(CStr8::value_type));
            }
        }

        // -=(Undocumented)=-
        void WriteString16(CStr16 Data)
        {
            WriteInt(Data.size());

            if (!Data.empty())
            {
                Write<CStr16::const_pointer>(Data.data(), Data.size() * sizeof(CStr16::value_type));
            }
        }

    private:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        Array<UInt08> mBuffer;
        UInt32        mOffset;
    };
}