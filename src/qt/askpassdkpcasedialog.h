// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ASKPASSDKPCASEDIALOG_H
#define BITCOIN_QT_ASKPASSDKPCASEDIALOG_H

#include <QDialog>

class WalletModel;

namespace Ui
{
class AskPassdkpcaseDialog;
}

/** Multifunctional dialog to ask for passdkpcases. Used for encryption, unlocking, and changing the passdkpcase.
 */
class AskPassdkpcaseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,         /**< Ask passdkpcase twice and encrypt */
        UnlockAnonymize, /**< Ask passdkpcase and unlock only for anonymization */
        Unlock,          /**< Ask passdkpcase and unlock */
        ChangePass,      /**< Ask old passdkpcase + new passdkpcase twice */
        Decrypt          /**< Ask passdkpcase and decrypt wallet */
    };

    explicit AskPassdkpcaseDialog(Mode mode, QWidget* parent, WalletModel* model);
    ~AskPassdkpcaseDialog();

    void accept();

private:
    Ui::AskPassdkpcaseDialog* ui;
    Mode mode;
    WalletModel* model;
    bool fCapsLock;

private slots:
    void textChanged();

protected:
    bool event(QEvent* event);
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // BITCOIN_QT_ASKPASSDKPCASEDIALOG_H
