/****************************************************************************
** Meta object code from reading C++ file 'candydialog.h'
**
** Created: Tue Sep 1 14:36:54 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "candydialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'candydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CandyDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      25,   12,   12,   12, 0x08,
      36,   12,   12,   12, 0x08,
      47,   12,   12,   12, 0x08,
      58,   12,   12,   12, 0x08,
      78,   67,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CandyDialog[] = {
    "CandyDialog\0\0startTest()\0stopTest()\0"
    "resetAll()\0nextTest()\0chTime()\0"
    "testMethod\0initialComboBoxHide(QString)\0"
};

void CandyDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CandyDialog *_t = static_cast<CandyDialog *>(_o);
        switch (_id) {
        case 0: _t->startTest(); break;
        case 1: _t->stopTest(); break;
        case 2: _t->resetAll(); break;
        case 3: _t->nextTest(); break;
        case 4: _t->chTime(); break;
        case 5: _t->initialComboBoxHide((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CandyDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CandyDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CandyDialog,
      qt_meta_data_CandyDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CandyDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CandyDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CandyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CandyDialog))
        return static_cast<void*>(const_cast< CandyDialog*>(this));
    if (!strcmp(_clname, "Ui::Candy"))
        return static_cast< Ui::Candy*>(const_cast< CandyDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CandyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
