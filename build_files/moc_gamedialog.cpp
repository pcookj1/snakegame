/****************************************************************************
** Meta object code from reading C++ file 'gamedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameDialog_t {
    QByteArrayData data[12];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameDialog_t qt_meta_stringdata_GameDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameDialog"
QT_MOC_LITERAL(1, 11, 8), // "gameOver"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "gamePaused"
QT_MOC_LITERAL(4, 32, 10), // "resumeGame"
QT_MOC_LITERAL(5, 43, 14), // "exitToMainMenu"
QT_MOC_LITERAL(6, 58, 9), // "playAgain"
QT_MOC_LITERAL(7, 68, 10), // "onGameOver"
QT_MOC_LITERAL(8, 79, 12), // "onGamePaused"
QT_MOC_LITERAL(9, 92, 8), // "setScore"
QT_MOC_LITERAL(10, 101, 5), // "score"
QT_MOC_LITERAL(11, 107, 9) // "highScore"

    },
    "GameDialog\0gameOver\0\0gamePaused\0"
    "resumeGame\0exitToMainMenu\0playAgain\0"
    "onGameOver\0onGamePaused\0setScore\0score\0"
    "highScore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    2,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,

       0        // eod
};

void GameDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameDialog *_t = static_cast<GameDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameOver(); break;
        case 1: _t->gamePaused(); break;
        case 2: _t->resumeGame(); break;
        case 3: _t->exitToMainMenu(); break;
        case 4: _t->playAgain(); break;
        case 5: _t->onGameOver(); break;
        case 6: _t->onGamePaused(); break;
        case 7: _t->setScore((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameDialog::gameOver)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameDialog::gamePaused)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameDialog::resumeGame)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameDialog::exitToMainMenu)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GameDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameDialog::playAgain)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_GameDialog.data,
    qt_meta_data_GameDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GameDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GameDialog::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameDialog::gamePaused()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GameDialog::resumeGame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void GameDialog::exitToMainMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void GameDialog::playAgain()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
