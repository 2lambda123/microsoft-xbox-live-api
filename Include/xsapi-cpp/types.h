// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#pragma once

#include <string>
#include <regex>
#include <chrono>
#include "xsapi-c/types_c.h"

#if HC_PLATFORM_IS_MICROSOFT
#define _XSAPICPP_DEPRECATED __declspec(deprecated)
#else
#define _XSAPICPP_DEPRECATED __attribute__ ((deprecated))
#endif

#if !HC_PLATFORM_IS_MICROSOFT || (defined(_MSC_VER) && (_MSC_VER >= 1900))
// VS2013 doesn't support default move constructor and assignment, so we implemented this.
// However, a user defined move constructor and assignment will implicitly delete default copy 
// constructor and assignment in other compiler like clang. So we only define this in Win32 under VS2013
#define DEFAULT_MOVE_ENABLED
#endif

typedef void* function_context;
#if HC_PLATFORM_IS_MICROSOFT
typedef wchar_t char_t;
typedef std::wstring string_t;
typedef std::wstringstream stringstream_t;
typedef std::wregex regex_t;
typedef std::wsmatch smatch_t;
#else
typedef char char_t;
typedef std::string string_t;
typedef std::stringstream stringstream_t;
typedef std::regex regex_t;
typedef std::smatch smatch_t;
#endif

#if _MSC_VER <= 1800
typedef std::chrono::system_clock chrono_clock_t;
#else
typedef std::chrono::steady_clock chrono_clock_t;
#endif

// Forward declarations
namespace xbox {
    namespace services {
        class xbox_live_context_settings;
        class JsonAllocator;
        namespace system {
            class xbox_live_user;
        }
    }
}

#if HC_PLATFORM != HC_PLATFORM_XDK
// SSL client certificate context
#if HC_PLATFORM_IS_MICROSOFT
#include <wincrypt.h>
typedef PCCERT_CONTEXT cert_context;
#endif
#endif

#if HC_PLATFORM == HC_PLATFORM_UWP
    typedef Windows::System::User^ user_creation_context;
#else
    typedef void* user_creation_context;
#endif

typedef XblUserHandle xbox_live_user_t;

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN                     namespace xbox { namespace services {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END                       }}
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN                         namespace Microsoft { namespace Xbox { namespace Services { 
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_END                           }}}

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SYSTEM_CPP_BEGIN              NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace system {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SYSTEM_CPP_END                NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SYSTEM_BEGIN                  NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace System { 
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SYSTEM_END                    NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_CPP_BEGIN              NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace social {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_CPP_END                NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_BEGIN                  NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Social {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_END                    NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_CPP_BEGIN        NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace achievements {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_CPP_END          NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_BEGIN            NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Achievements {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_END              NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_MANAGER_CPP_BEGIN NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace achievements { namespace manager {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_MANAGER_CPP_END   NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END } }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_MANAGER_BEGIN     NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Achievements { namespace Manager {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ACHIEVEMENTS_MANAGER_END       NAMESPACE_MICROSOFT_XBOX_SERVICES_END } }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_LEADERBOARD_CPP_BEGIN         NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace leaderboard {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_LEADERBOARD_CPP_END           NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_LEADERBOARD_BEGIN             NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Leaderboard {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_LEADERBOARD_END               NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_USERSTATISTICS_CPP_BEGIN      NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace user_statistics {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_USERSTATISTICS_CPP_END        NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_USERSTATISTICS_BEGIN          NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace UserStatistics {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_USERSTATISTICS_END            NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MULTIPLAYER_CPP_BEGIN         NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace multiplayer {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MULTIPLAYER_CPP_END           NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MULTIPLAYER_BEGIN             NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Multiplayer {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MULTIPLAYER_END               NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MATCHMAKING_CPP_BEGIN         NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace matchmaking {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MATCHMAKING_CPP_END           NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MATCHMAKING_BEGIN             NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Matchmaking {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MATCHMAKING_END               NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MARKETPLACE_CPP_BEGIN         NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace marketplace {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MARKETPLACE_CPP_END           NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MARKETPLACE_BEGIN             NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Marketplace {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MARKETPLACE_END               NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PRIVACY_CPP_BEGIN             NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace privacy {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PRIVACY_CPP_END               NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PRIVACY_BEGIN                 NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Privacy {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PRIVACY_END                   NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_RTA_CPP_BEGIN                 NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace real_time_activity {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_RTA_CPP_END                   NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_RTA_BEGIN                     NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace RealTimeActivity {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_RTA_END                       NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PRESENCE_CPP_BEGIN            NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace presence {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PRESENCE_CPP_END              NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PRESENCE_BEGIN                NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Presence {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PRESENCE_END                  NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_GAMESERVERPLATFORM_CPP_BEGIN  NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace game_server_platform {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_GAMESERVERPLATFORM_CPP_END    NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_GAMESERVERPLATFORM_BEGIN      NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace GameServerPlatform {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_GAMESERVERPLATFORM_END        NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_TITLE_STORAGE_CPP_BEGIN       NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace title_storage {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_TITLE_STORAGE_CPP_END         NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_TITLE_STORAGE_BEGIN           NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace TitleStorage {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_TITLE_STORAGE_END             NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_EVENTS_CPP_BEGIN              NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace events {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_EVENTS_CPP_END                NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_EVENTS_BEGIN                  NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Events {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_EVENTS_END                    NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CONTEXTUAL_SEARCH_CPP_BEGIN   NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace contextual_search {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CONTEXTUAL_SEARCH_CPP_END     NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CONTEXTUAL_SEARCH_BEGIN       NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace ContextualSearch {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CONTEXTUAL_SEARCH_END         NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ENTERTAINMENT_PROFILE_CPP_BEGIN   NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace entertainment_profile {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ENTERTAINMENT_PROFILE_CPP_END     NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ENTERTAINMENT_PROFILE_BEGIN       NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace EntertainmentProfile {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_ENTERTAINMENT_PROFILE_END         NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_NOTIFICATION_CPP_BEGIN        NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace notification {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_NOTIFICATION_CPP_END          NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MULTIPLAYER_MANAGER_CPP_BEGIN NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace multiplayer { namespace manager {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MULTIPLAYER_MANAGER_CPP_END   NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END } }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MULTIPLAYER_MANAGER_BEGIN     NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Multiplayer { namespace Manager {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_MULTIPLAYER_MANAGER_END       NAMESPACE_MICROSOFT_XBOX_SERVICES_END } }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_EXPERIMENTAL_CPP_BEGIN        NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace experimental {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_EXPERIMENTAL_CPP_END          NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_EXPERIMENTAL_BEGIN            NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Experimental {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_EXPERIMENTAL_END              NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_MANAGER_CPP_BEGIN     NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace social { namespace manager {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_MANAGER_CPP_END       NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END } }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_MANAGER_BEGIN         NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Social { namespace Manager {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_SOCIAL_MANAGER_END           NAMESPACE_MICROSOFT_XBOX_SERVICES_END } }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_STAT_MANAGER_CPP_BEGIN     NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace stats { namespace manager {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_STAT_MANAGER_CPP_END       NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END } }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_STATISTIC_MANAGER_BEGIN         NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Statistics { namespace Manager {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_STATISTIC_MANAGER_END           NAMESPACE_MICROSOFT_XBOX_SERVICES_END } }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PLAYER_STATE_CPP_BEGIN   NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace player_state {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PLAYER_STATE_CPP_END     NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PLAYER_STATE_BEGIN       NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace PlayerState {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_PLAYER_STATE_END         NAMESPACE_MICROSOFT_XBOX_SERVICES_END }

#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CLUBS_CPP_BEGIN          NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_BEGIN namespace clubs {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CLUBS_CPP_END            NAMESPACE_MICROSOFT_XBOX_SERVICES_CPP_END }
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CLUBS_BEGIN              NAMESPACE_MICROSOFT_XBOX_SERVICES_BEGIN namespace Clubs {
#define NAMESPACE_MICROSOFT_XBOX_SERVICES_CLUBS_END                NAMESPACE_MICROSOFT_XBOX_SERVICES_END }
