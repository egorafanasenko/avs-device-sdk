/*
 * AudioInputProcessor.cpp
 *
 * Copyright 2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include "AIP/MessageRequest.h"

#include <AVSCommon/Utils/Logger/Logger.h>

namespace alexaClientSDK {
namespace capabilityAgents {
namespace aip {

/// String to identify log entries originating from this file.
static const std::string TAG("MessageRequest");

/**
 * Create a LogEntry using this file's TAG and the specified event string.
 *
 * @param The event string for this @c LogEntry.
 */
#define LX(event) alexaClientSDK::avsCommon::utils::logger::LogEntry(TAG, event)

MessageRequest::MessageRequest(
        std::shared_ptr<AudioInputProcessor> audioInputProcessor,
        const std::string& jsonContent,
        std::shared_ptr<avsCommon::avs::attachment::AttachmentReader> attachmentReader) :
        avsCommon::avs::MessageRequest{jsonContent, attachmentReader}, m_audioInputProcessor{audioInputProcessor} {
}

void MessageRequest::onExceptionReceived(const std::string& exceptionMessage) {

    ACSDK_ERROR(LX("onExceptionReceived").d("exception", exceptionMessage));
    m_audioInputProcessor->resetState();
}


} // namespace aip
} // namespace capabilityAgents
} // namespace alexaClientSDK
