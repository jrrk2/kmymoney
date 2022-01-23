/*
    SPDX-FileCopyrightText: 2017, 2018 Łukasz Wojniłowicz <lukasz.wojnilowicz@gmail.com>
    SPDX-License-Identifier: GPL-2.0-or-later
*/

#ifndef MENUENUMS_H
#define MENUENUMS_H

#include "kmm_menus_export.h"
#include <QHashFunctions>
#include <QHash>

class QAction;
class QMenu;

namespace eMenu {
// clang-format off
enum class Action {
    // *************
    // The File menu
    // *************
    None,
    FileNew, FileClose,
    FileOpenDatabase, FileSaveAsDatabase, FileBackup,
    FileImportStatement,
    FileImportTemplate, FileExportTemplate,
    Print,
    PrintPreview,
#ifdef KMM_DEBUG
    FileDump,
#endif
    FilePersonalData, FileInformation,
    // *************
    // The edit menu
    // *************
    EditFindTransaction,
    EditUndo,
    EditRedo,
    // *************
    // The view menu
    // *************
    ViewTransactionDetail, ViewHideReconciled,
    ViewHideCategories, ViewShowAll,
    // *************
    // The institution menu
    // *************
    NewInstitution, EditInstitution,
    DeleteInstitution,

    // *************
    // The account menu
    // *************
    NewAccount, EditAccount, DeleteAccount,
    OpenAccount, CloseAccount, ReopenAccount,
    StartReconciliation, FinishReconciliation,
    PostponeReconciliation,
    CancelReconciliation,
    ReconciliationReport,
    ReportAccountTransactions, ChartAccountBalance,
    UpdateAccountMenu, UpdateAccount, UpdateAllAccounts,
    MapOnlineAccount, UnmapOnlineAccount,
    // *************
    // The category menu
    // *************
    NewCategory, EditCategory, DeleteCategory,
    // *************
    // The transaction menu
    // *************
    NewTransaction, EditTransaction, DeleteTransaction,
    EnterTransaction, CancelTransaction,
    DuplicateTransaction, AddReversingTransaction,
    MatchTransaction, AcceptTransaction,
    EditSplits, CopySplits,
    ToggleReconciliationFlag, MarkCleared,
    MarkReconciled, MarkNotReconciled,
    SelectAllTransactions,
    GoToAccount, GoToPayee,
    NewScheduledTransaction, AssignTransactionsNumber,
    CombineTransactions,
    MoveTransactionTo,
    // *************
    // The tools menu
    // *************
    ToolCurrencies,
    ToolPrices, ToolUpdatePrices,
    ToolConsistency, ToolPerformance,
    ToolSQL, ToolCalculator,
    // *************
    // The help menu
    // *************
    SettingsAllMessages,
    // *************
    // The investment menu
    // *************
    NewInvestment, EditInvestment, DeleteInvestment,
    UpdatePriceOnline, UpdatePriceManually,
    EditSecurity, DeleteSecurity,
    // *************
    // The schedule menu
    // *************
    NewSchedule, EditSchedule,
    DeleteSchedule, DuplicateSchedule,
    EnterSchedule, SkipSchedule,
    // *************
    // The payee menu
    // *************
    NewPayee, RenamePayee, DeletePayee,
    MergePayee,
    // *************
    // The tag menu
    // *************
    NewTag, RenameTag, DeleteTag,
    // *************
    // The show actions
    // *************
    ShowHomeView, ShowInstitutionsView, ShowAccountsView,
    ShowSchedulesView, ShowCategoriesView, ShowTagsView,
    ShowPayeesView, ShowLedgersView, ShowInvestmentsView,
    ShowReportsView, ShowBudgetView, ShowForecastView,
    ShowOnlineJobOutboxView, ShowFilterWidget,
    // *************
    // The misc actions
    // *************
    EditTabOrder,
#ifdef KMM_DEBUG
    NewFeature, DebugTraces,
#endif
    DebugTimers,
    DeleteOnlineJob, EditOnlineJob, LogOnlineJob,
    ReportOpen, ReportNew, ReportCopy, ReportConfigure,
    ReportExport, ReportDelete, ReportClose, ReportToggleChart,
    // *************
    // Actions only used by code
    // *************
    ShowTransaction,
};
// clang-format on

inline uint qHash(const Action key, uint seed) {
    return ::qHash(static_cast<uint>(key), seed);
}

enum class Menu {
    Institution,
    Account,
    Schedule,
    Category,
    Tag,
    Payee,
    Investment,
    Security,
    Transaction,
    MoveTransaction,
    MarkTransaction,
    MarkTransactionContext,
    OnlineJob,
};

inline uint qHash(const Menu key, uint seed) {
    return ::qHash(static_cast<uint>(key), seed);
}
}

KMM_MENUS_EXPORT extern QHash<eMenu::Action, QAction *> pActions;
KMM_MENUS_EXPORT extern QHash<eMenu::Menu, QMenu *> pMenus;

#endif
