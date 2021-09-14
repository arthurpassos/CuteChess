//
// Created by Passos, Arthur on 26/11/20.
//

#ifndef CHESS1_EVENTSONGEFFECTREPOSITORY_H
#define CHESS1_EVENTSONGEFFECTREPOSITORY_H


#include <QSoundEffect>

// não consegui achar sons :(
class EventSongEffectRepository {

    enum Event {
        CAPTURE,
        MOVE,
        CASTLE
    };

    static QSoundEffect create(Event event);
};


#endif //CHESS1_EVENTSONGEFFECTREPOSITORY_H
