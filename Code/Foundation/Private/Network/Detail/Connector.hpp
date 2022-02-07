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

#include "Network/Detail/Channel.hpp"
#include "Network/Client.hpp"

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// [   CODE   ]
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

namespace Aurora::Network::Detail
{
    // -=(Undocumented)=-
    class Connector final : public Network::Client
    {
    public:

        // -=(Undocumented)=-
        Connector();

        // -=(Undocumented)=-
        ~Connector() override;

        // \inheritDoc
        void Poll() override;

        // \inheritDoc
        void Attach(OnAttach OnAttach, OnDetach OnDetach, OnForward OnForward, OnReceive OnReceive) override;

        // \inheritDoc
        void Connect(CStr8 Address, CStr8 Service) override;

        // \inheritDoc
        void Close(Bool Force) override;

        // \inheritDoc
        void Send(Bool Urgent, Writer & Message) override;

        // \inheritDoc
        void Flush() override;

        // \inheritDoc
        Statistics GetStatistics() const override;

    private:

        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
        // -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

        asio::io_context mContext;
        SPtr<Channel>    mChannel;
    };
}