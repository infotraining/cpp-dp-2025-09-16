#include "factory.hpp"

#include <cstdlib>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

namespace StronglyCoupled
{
    class MusicApp
    {
    public:
        MusicApp() = default;

        void play(const std::string &track_title)
        {
            // creation of product
            SpotifyService music_service("spotify_user", "rjdaslf276%2", 45);

            std::optional<Track> track = music_service.get_track(track_title);

            if (track)
            {
                std::cout << "Playing track: ";
                for (const auto &note : *track)
                    std::cout << note << ".";
                std::cout << "|\n";
            }
            else
            {
                std::cout << "Track not found!\n";
            }
        }
    };
}

namespace Canonical
{
    class MusicApp
    {
        std::shared_ptr<MusicServiceCreator> music_service_creator_;

    public:
        MusicApp(std::shared_ptr<MusicServiceCreator> music_service_creator)
            : music_service_creator_(music_service_creator)
        {
        }

        void play(const std::string &track_title)
        {
            // creation of the object
            std::unique_ptr<MusicService> music_service = music_service_creator_->create_music_service();

            // usage of the object
            std::optional<Track> track = music_service->get_track(track_title);

            if (track)
            {
                std::cout << "Playing track: ";
                for (const auto &note : *track)
                    std::cout << note << ".";
                std::cout << "|\n";
            }
            else
            {
                std::cout << "Track not found!\n";
            }
        }
    };

    // parametrized factory
    using MusicServiceFactory = std::unordered_map<std::string, std::shared_ptr<MusicServiceCreator>>;
}

namespace ModernCpp
{
    class MusicApp
    {
        MusicServiceCreator music_service_creator_;

    public:
        MusicApp(MusicServiceCreator music_service_creator)
            : music_service_creator_(music_service_creator)
        {
        }

        void play(const std::string &track_title)
        {
            // creation of the object
            std::unique_ptr<MusicService> music_service = music_service_creator_();

            // usage of the object
            std::optional<Track> track = music_service->get_track(track_title);

            if (track)
            {
                std::cout << "Playing track: ";
                for (const auto &note : *track)
                    std::cout << note << ".";
                std::cout << "|\n";
            }
            else
            {
                std::cout << "Track not found!\n";
            }
        }
    };

    using MusicServiceFactory = std::unordered_map<std::string, MusicServiceCreator>;
}

// parametrized factory

int main()
{
    using namespace ModernCpp;
    
    MusicServiceFactory music_service_factory;
    music_service_factory.emplace("Tidal", TidalServiceCreator("tidal_user", "KJH8324d&df"));
    music_service_factory.emplace("Spotify", SpotifyServiceCreator("spotify_user", "rjdaslf276%2", 45));
    music_service_factory.emplace("Filesystem", []()
                                  { return std::make_unique<FilesystemMusicService>("/my_music"); });
    music_service_factory.emplace("YouTube", YouTubeMusicServiceCreator("yt_user", "yt_secret", true));

    std::string id_from_config = "YouTube";
    MusicApp app(music_service_factory.at(id_from_config));
    app.play("Would?");
}