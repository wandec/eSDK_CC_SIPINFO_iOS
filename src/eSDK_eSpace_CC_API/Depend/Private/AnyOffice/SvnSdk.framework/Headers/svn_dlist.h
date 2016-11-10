/******************************************************************************

                  版权所有 (C), 2001-2011, 华为技术有限公司

 ******************************************************************************
  文 件 名   : svn_dlist.h
  版 本 号   : 初稿
  作    者   : fengzhengyu
  生成日期   : 2012年5月2日
  最近修改   :
  功能描述   : svn双链表头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2012年5月2日
    作    者   : fengzhengyu
    修改内容   : 创建文件

******************************************************************************/
#ifndef SVN_DLIST_H__
#define SVN_DLIST_H__

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef offset_of
#define offset_of(type, memb) \
    (unsigned long)(&((type *)0)->memb)
#endif

#ifndef container_of
#define container_of(obj, type, memb) \
    ((type *)(((char *)obj) - offset_of(type, memb)))
#endif

typedef struct tagSVN_DList_Head
{
    struct tagSVN_DList_Head *pstNext;
    struct tagSVN_DList_Head *pstPrev;
}SVN_DLIST_HEAD_S;

#define SVN_DLIST_HEAD_ASSIGN(name) { &(name), &(name) }

#define SVN_DLIST_HEAD(name) \
    SVN_DLIST_HEAD_S name = SVN_DLIST_HEAD_ASSIGN(name)

#define SVN_DLIST_ENTRY(ptr, type, member) \
    container_of(ptr, type, member)

#define SVN_DLIST_FIRST_ENTRY(ptr, type, member) \
    SVN_DLIST_ENTRY((ptr)->pstNext, type, member) \

#define SVN_DILST_LAST_ENTRY(ptr, type, member) \
    SVN_DLIST_ENTRY((ptr)->pstPrev, type, member)

#define SVN_DLIST_FOR_EACH(pos, head) \
    for (pos = (head)->pstNext; (pos) != (head); pos = pos->pstNext) \

#define SVN_DLIST_FOR_EACH_ENTRY(pos, pstHead, type, member)          \
    for (pos = SVN_DLIST_ENTRY((pstHead)->pstNext, type, member); \
        &pos->member != (pstHead);   \
        pos = SVN_DLIST_ENTRY(pos->member.pstNext, type, member))  \

#define SVN_DLIST_FREENODES(ptr, type, member) \
        do{\
            type *pstNode2Del = NULL;\
            while(VOS_FALSE == SVN_DList_Empty(ptr))\
            {\
                pstNode2Del = SVN_DLIST_ENTRY((ptr)->pstNext, type, member);\
                SVN_DList_DelInit(&pstNode2Del->member);\
                MDM_Free(pstNode2Del);\
            }\
        }while(0);

void SVN_DList_HeadInit(SVN_DLIST_HEAD_S *pstList);

void SVN_DList_AddNext(SVN_DLIST_HEAD_S *pstNew, SVN_DLIST_HEAD_S *pstHead);
void SVN_DList_AddPrev(SVN_DLIST_HEAD_S *pstNew, SVN_DLIST_HEAD_S *pstHead);

void SVN_DList_DelInit(SVN_DLIST_HEAD_S *pstEntry);
void SVN_DList_DelSafe(SVN_DLIST_HEAD_S *pstEntry);

SVN_DLIST_HEAD_S* SVN_DList_Remove(SVN_DLIST_HEAD_S *pstHead);
SVN_DLIST_HEAD_S* SVN_DList_RemoveTail(SVN_DLIST_HEAD_S *pstHead);

long SVN_DList_Empty(const SVN_DLIST_HEAD_S *pstHead);

long SVN_DList_IsLast(const SVN_DLIST_HEAD_S *pstList, const SVN_DLIST_HEAD_S *pstHead);
long SVN_DList_IsSingular(const SVN_DLIST_HEAD_S *pstHead);
long SVN_DList_IsBeyondSingular(const SVN_DLIST_HEAD_S *pstHead);
long SVN_DList_IsLinked(const SVN_DLIST_HEAD_S *pstEntry);

void SVN_DList_SpliceInit(SVN_DLIST_HEAD_S *pstList, SVN_DLIST_HEAD_S *pstHead);

void *SVN_DList_GetNext(void *pCur, void **ppNext);

#define SVN_DLIST_FOR_EACH_ENTRY_SAFE(pos, tmp, pstHead, type, member) \
    for (pos = SVN_DLIST_FIRST_ENTRY(pstHead, type, member), \
        tmp = SVN_DLIST_ENTRY(pos->member.pstNext, type, member); \
        &pos->member != (pstHead); \
        pos = tmp, tmp = SVN_DLIST_ENTRY(tmp->member.pstNext, type, member))


#ifdef __cplusplus
}
#endif

#endif
