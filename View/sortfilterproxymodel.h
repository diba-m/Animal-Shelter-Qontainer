#ifndef SORTFILTERPROXYMODEL_H
#define SORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class SortFilterProxyModel: public QSortFilterProxyModel
{
public:
    using QSortFilterProxyModel::QSortFilterProxyModel;
    QString fixedString() const;
    void setFixedString(const QString &fixedString);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
private:
    QString m_fixedString;
};

#endif // SORTFILTERPROXYMODEL_H
