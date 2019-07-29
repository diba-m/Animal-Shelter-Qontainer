#include "sortfilterproxymodel.h"

void SortFilterProxyModel::setFixedString(const QString &fixedString){
    if(m_fixedString == fixedString) return;
    m_fixedString = fixedString;
    invalidateFilter();
}
bool SortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if(m_fixedString.isEmpty())
        return true;
    QModelIndex ix = sourceModel()->index(source_row, filterKeyColumn(), source_parent);
    return ix.data().toString() == m_fixedString;
}

