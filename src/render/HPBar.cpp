//
// Created by patrick on 2/11/16.
//

#include "HPBar.h"

namespace lg
{
    HPBar::HPBar(GameData *data, int x, int y, SDL_Color color) :
        _data(data),
        _text(nullptr),
        _x(x),
        _y(y),
        _color(color),
        _val(100),
        _targetVal(100),
        _lastUpdate(0.0)
    {
        _text = _getHPText(_val);
    }

    void HPBar::update(double dt)
    {
        _lastUpdate += dt;
        if (_lastUpdate > 0.05)
        {
            if (_targetVal > _val)
            {
                _val += 1;
                _text = _getHPText(_val);
            }
            else if (_targetVal < _val)
            {
                _val -= 1;
                _text = _getHPText(_val);
            }
            _lastUpdate = 0.0;
        }
    }

    void HPBar::render()
    {
        _data->getRenderer().Copy(*_text, SDL2pp::NullOpt, SDL2pp::Point(_x, _y));
    }

    void HPBar::setHP(int target)
    {
        _targetVal = target > 0 ? target < 100 ? target : 100 : 0;
    }

    int HPBar::getHP()
    {
        return _val;
    }

    SDL2pp::Texture *HPBar::_getHPText(int val)
    {
        return _data->getAssetManager().loadFontTexture(
                _data->getRenderer(), _data->getFont(), std::string("HP: ") + std::to_string(val) + std::string("%"), _color);
    }
}