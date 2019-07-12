//
// Created by vinokurov on 12.07.2019.
//

#include "NotAllUserDataSetPackage.h"

using namespace std::string_literals;

NotAllUserDataSetPackage::NotAllUserDataSetPackage(Player &player) :
        ErrorPackage(6),
        _player{ player }
{

}

std::string_view NotAllUserDataSetPackage::getErrorMessage() const {
    return "У пользователя установлены не все данные.";
}
