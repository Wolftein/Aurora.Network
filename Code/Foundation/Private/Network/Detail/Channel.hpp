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

#include "Network/Reader.hpp"
#include "Network/Writer.hpp"
#include "Network/Detail/Buffer.hpp"
#include <asio.hpp>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

namespace Aurora::Network::Detail
{
    // -=(Undocumented)=-
    class Channel : public eastl::enable_shared_from_this<Channel>
    {
    public:

        // -=(Undocumented)=-
        using OnAttach  = Method<void(const SPtr<Channel> & Channel)>;

        // -=(Undocumented)=-
        using OnDetach  = Method<void(const SPtr<Channel> & Channel, SInt32 Code)>;

        // -=(Undocumented)=-
        using OnForward = Method<void(const SPtr<Channel> & Channel, CPtr<UInt08> Data)>;

        // -=(Undocumented)=-
        using OnReceive = Method<void(const SPtr<Channel> & Channel, CPtr<UInt08> Data)>;

        // -=(Undocumented)=-
        enum class State
        {
            Connecting,
            Connected,
            Closing,
            Closed,
        };

        // -=(Undocumented)=-
        enum class Sequence
        {
            Header, Body
        };

    public:

        // -=(Undocumented)=-
        explicit Channel(asio::ip::tcp::socket && Channel);

        // -=(Undocumented)=-
        void SetID(UInt32 ID);

        // -=(Undocumented)=-
        UInt32 GetID() const;

        // -=(Undocumented)=-
        Str8 GetAddress() const;

        // -=(Undocumented)=-
        void Attach(OnAttach OnAttach, OnDetach OnDetach, OnForward OnForward, OnReceive OnReceive);

        // -=(Undocumented)=-
        void Connect(CStr8 Address, CStr8 Service);

        // -=(Undocumented)=-
        void Close(Bool Force);

        // -=(Undocumented)=-
        void Send(Bool Urgent, Writer & Message);

        // -=(Undocumented)=-
        void Flush();

        // -=(Undocumented)=-
        void Start();

    private:

        // -=(Undocumented)=-
        void DoClose(SInt32 Code);

        // -=(Undocumented)=-
        void DoConfiguration();

        // -=(Undocumented)=-
        void DoRead(Sequence Operation, UInt32 Quantity);

        // -=(Undocumented)=-
        void DoFlush();

        // -=(Undocumented)=-
        void DoProcess();

        // -=(Undocumented)=-
        void WhenResolve(const std::error_code & Error, asio::ip::tcp::resolver::iterator Result);

        // -=(Undocumented)=-
        void WhenConnect(const std::error_code & Error, asio::ip::tcp::resolver::iterator Result);

        // -=(Undocumented)=-
        void WhenError(const std::error_code & Error);

        // -=(Undocumented)=-
        void WhenRead(const std::error_code & Error, UInt32 Transferred, Sequence Operation);

        // -=(Undocumented)=-
        void WhenWrite(const std::error_code & Error, UInt32 Transferred);

    private:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        UInt32                mID;
        asio::ip::tcp::socket mChannel;
        State                 mState;

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        Buffer                mEncoder;
        Buffer                mDecoder;
        UInt16                mWriter;
        UInt16                mHeader;

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        OnAttach              mOnAttach;
        OnDetach              mOnDetach;
        OnForward             mOnForward;
        OnReceive             mOnReceive;
    };
}
