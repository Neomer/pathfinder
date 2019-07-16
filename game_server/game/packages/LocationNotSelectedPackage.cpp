//
// Created by kir on 13.07.19.
//

#include "LocationNotSelectedPackage.h"

using namespace std::string_literals;

LocationNotSelectedPackage::LocationNotSelectedPackage(const Player &player) :
        ErrorPackage(8),
        _player{ player }
{

}

std::string_view LocationNotSelectedPackage::getErrorMessage() const
{
    return "Пользователь "s + _player.getName() + " не выбрал локацию!";
}
