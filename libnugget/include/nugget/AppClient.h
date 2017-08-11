
/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NUGGET_APP_CLIENT_H
#define NUGGET_APP_CLIENT_H

#include <cstdint>
#include <vector>

#include <nugget/NuggetClient.h>

namespace nugget {

/**
 * Client to communicate with an app running on Nugget OS.
 */
class AppClient {
public:
    /**
     * Create a client for an app with the given ID that communicates with
     * Nugget OS through the given NuggetClient.
     *
     * @param client Client for Nugget OS.
     * @param appId  ID of the target app.
     */
    AppClient(NuggetClient& client, uint32_t appId)
            : _client{client}, _appId{appId} {}

    /**
     * Call the app.
     *
     * @param arg      Argument to pass to the app.
     * @param request  Data to send to the app.
     * @param response Buffer to receive data from the app.
     */
    uint32_t call(uint16_t arg, const std::vector<uint8_t>& request,
                  std::vector<uint8_t>& response) {
        return _client.callApp(_appId, arg, request, response);
    }


private:
    NuggetClient& _client;
    uint32_t _appId;
};

} // namespace nugget

#endif // NUGGET_APP_CLIENT_H
