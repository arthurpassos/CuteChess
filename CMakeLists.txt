cmake_minimum_required(VERSION 3.17)
project(Chess1)

set(CMAKE_CXX_STANDARD 20)

add_library(range_v3 INTERFACE IMPORTED)
set_target_properties(range_v3 PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES $ENV{HOME}/range-v3/include)

set (CMAKE_PREFIX_PATH /usr/local/Cellar/qt@5/5.15.2)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(Chess1 main.cpp domain/Board.cpp domain/Board.h game/LocalGame.cpp game/LocalGame.h domain/player/Player.cpp domain/player/Player.h domain/player/IPlayer.h domain/move/Move.cpp domain/move/Move.h domain/Position.cpp domain/Position.h game/IGame.h controller/GameController.cpp controller/GameController.h ui/SquareItem.cpp ui/SquareItem.h ui/util/PieceImageFactory.cpp ui/util/PieceImageFactory.h lib/magic_enum.h domain/pieces/IPiece.h domain/pieces/PieceBase.cpp domain/pieces/PieceBase.h domain/pieces/Pawn.cpp domain/pieces/Pawn.h domain/pieces/Rook.cpp domain/pieces/Rook.h domain/pieces/Knight.cpp domain/pieces/Knight.h domain/pieces/Bishop.cpp domain/pieces/Bishop.h domain/pieces/Queen.cpp domain/pieces/Queen.h domain/pieces/King.cpp domain/pieces/King.h ui/GameScene.cpp ui/GameScene.h game/GameLauncher.cpp game/GameLauncher.h ui/PieceWithImage.cpp ui/PieceWithImage.h ui/util/EventSongEffectRepository.cpp ui/util/EventSongEffectRepository.h domain/move/FriendFireFilter.cpp domain/move/FriendFireFilter.h domain/move/AttackedSquaresMoveFilter.cpp domain/move/AttackedSquaresMoveFilter.h)

target_link_libraries(Chess1 Qt5::Widgets Qt5::Multimedia range_v3)