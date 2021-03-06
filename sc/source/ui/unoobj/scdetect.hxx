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

#ifndef INCLUDED_SC_SOURCE_UI_UNOOBJ_SCDETECT_HXX
#define INCLUDED_SC_SOURCE_UI_UNOOBJ_SCDETECT_HXX

#include <com/sun/star/document/XExtendedFilterDetection.hpp>
#include <com/sun/star/uno/Exception.hpp>
#include <com/sun/star/uno/Reference.h>
#include <cppuhelper/implbase.hxx>

#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XSingleServiceFactory.hpp>
#include <cppuhelper/factory.hxx>

#include <rtl/ustring.hxx>
#include <sfx2/sfxuno.hxx>

namespace com { namespace sun { namespace star {
    namespace beans { struct PropertyValue; }
}}}

class ScFilterDetect : public ::cppu::WeakImplHelper< ::com::sun::star::document::XExtendedFilterDetection, ::com::sun::star::lang::XServiceInfo >
{
public:
    ScFilterDetect( const com::sun::star::uno::Reference<com::sun::star::uno::XComponentContext>& xContext );
    virtual ~ScFilterDetect();

    /* XServiceInfo */
    virtual OUString SAL_CALL getImplementationName() throw( com::sun::star::uno::RuntimeException, std::exception ) SAL_OVERRIDE;
    virtual sal_Bool SAL_CALL supportsService( const OUString& sServiceName ) throw( com::sun::star::uno::RuntimeException, std::exception ) SAL_OVERRIDE;
    virtual com::sun::star::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() throw( com::sun::star::uno::RuntimeException, std::exception ) SAL_OVERRIDE;

    // XExtendedFilterDetect

    virtual OUString SAL_CALL detect( com::sun::star::uno::Sequence<com::sun::star::beans::PropertyValue>& lDescriptor )
        throw (com::sun::star::uno::RuntimeException, std::exception) SAL_OVERRIDE;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
