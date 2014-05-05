#ifndef CONTENT_HPP
#define CONTENT_HPP
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <string>
#include <map>

namespace Suidao {

enum ContentType { GRAPHIC, SOUND, MUSIC, OTHER };

class Content {
    std::map<std::string,SDL_Texture*> _graphics;
    std::map<std::string,Mix_Chunk*> _sounds;
    std::map<std::string,Mix_Music*> _musics;
    void _LoadFolder(std::string root, std::string path,
                     SDL_Renderer* renderer);
    ContentType _FileType(std::string path);
  public:
    void LoadContent(std::string folder, SDL_Renderer* renderer);
    SDL_Texture* GetGraphic(std::string path) const;
    Mix_Chunk* GetSound(std::string path) const;
    Mix_Music* GetMusic(std::string path) const;
};

}

#endif // CONTENT_HPP
