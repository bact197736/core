/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_SVX_SVDOPAGE_HXX
#define INCLUDED_SVX_SVDOPAGE_HXX

#include <svx/svdobj.hxx>
#include <svx/sdrpageuser.hxx>
#include <svx/svxdllapi.h>

class SVX_DLLPUBLIC SdrPageObj : public SdrObject, public sdr::PageUser
{
public:
    // this method is called form the destructor of the referenced page.
    // do all necessary action to forget the page. It is not necessary to call
    // RemovePageUser(), that is done form the destructor.
    virtual void PageInDestruction(const SdrPage& rPage) SAL_OVERRIDE;

private:
    // To make things more safe, remember the page, not a number
    SdrPage*                                mpShownPage;

protected:
    virtual sdr::contact::ViewContact* CreateObjectSpecificViewContact() SAL_OVERRIDE;
    virtual sdr::properties::BaseProperties* CreateObjectSpecificProperties() SAL_OVERRIDE;

public:
    TYPEINFO_OVERRIDE();
    SdrPageObj(SdrPage* pNewPage = 0L);
    SdrPageObj(const Rectangle& rRect, SdrPage* pNewPage = 0L);
    virtual ~SdrPageObj();

    SdrPage* GetReferencedPage() const { return mpShownPage;}
    void SetReferencedPage(SdrPage* pNewPage);

    // #i96598#
    virtual void SetBoundRectDirty() SAL_OVERRIDE;

    virtual sal_uInt16 GetObjIdentifier() const SAL_OVERRIDE;
    virtual void TakeObjInfo(SdrObjTransformInfoRec& rInfo) const SAL_OVERRIDE;
    virtual SdrPageObj* Clone() const SAL_OVERRIDE;
    SdrPageObj& operator=(const SdrPageObj& rObj);

    virtual OUString TakeObjNameSingul() const SAL_OVERRIDE;
    virtual OUString TakeObjNamePlural() const SAL_OVERRIDE;
};



#endif // INCLUDED_SVX_SVDOPAGE_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
