//
// Copyright 2018 Ettus Research, a National Instruments Company
//
// SPDX-License-Identifier: GPL-3.0-or-later
//

#pragma once

#include <boost/noncopyable.hpp>
#include <memory>
#include <string>

namespace mpm { namespace i2c {

    /*! Implementation of a uhd::i2c_iface that uses Linux's i2c-dev underneath.
     */
    class i2c_iface : public boost::noncopyable
    {
    public:
        using sptr = std::shared_ptr<i2c_iface>;

        /*!
         * \param bus The path to the i2c bus segment used (e.g. "/dev/i2c3")
         * \param addr Address of the slave device on the bus segment
         * \param ten_bit_addr Whether the slave device's address is 10 bits
         * \param timeout_ms Time to wait for ACK from slave device
         */
        static sptr make_i2cdev(
            const std::string &bus,
            const uint16_t addr,
            const bool ten_bit_addr,
            const int timeout_ms
        );

        /*!
         * \param tx Buffer of data to send
         * \param tx_len Size (in bytes) of TX buffer
         * \param rx Buffer to hold read data
         * \param rx_len Number of bytes to read
         */
        virtual int transfer(uint8_t *tx, size_t tx_len, uint8_t *rx, size_t rx_len) = 0;
    };

}}; /* namespace mpm::i2c */
