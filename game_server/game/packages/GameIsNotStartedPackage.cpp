//
// Created by kir on 22.07.19.
//

#include "GameIsNotStartedPackage.h"

std::string_view GameIsNotStartedPackage::getErrorMessage() const
{
    return "Игра не начата!";
}

GameIsNotStartedPackage::GameIsNotStartedPackage() :
        ErrorPackage(9)
{

}
