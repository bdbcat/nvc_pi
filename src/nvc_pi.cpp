/******************************************************************************
 * $Id: nvc_pi.cpp,v 1.8 2010/06/21 01:54:37 bdbcat Exp $
 *
 * Project:  OpenCPN
 * Purpose:  NVC PlugIn
 * Author:   David Register
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register   *
 *   $EMAIL$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */


#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

//#include <vld.h>

#include "nvc_pi.h"
#include "chart.h"


// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new nvc_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}





//---------------------------------------------------------------------------------------------------------
//
//    PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "default_pi.xpm"


//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

nvc_pi::nvc_pi(void *ppimgr)
      :opencpn_plugin(ppimgr)
{
      // Create the PlugIn icons

      m_pplugin_icon = new wxBitmap(default_pi);
}

nvc_pi::~nvc_pi()
{
      delete m_pplugin_icon;
}

int nvc_pi::Init(void)
{

      AddLocaleCatalog( _T("opencpn-nvc_pi") );

      //    Build an arraystring of dynamically loadable chart class names
      m_class_name_array.Add(_T("ChartNVC"));

      return (INSTALLS_PLUGIN_CHART);

}

bool nvc_pi::DeInit(void)
{
      return true;
}

int nvc_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int nvc_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int nvc_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int nvc_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *nvc_pi::GetPlugInBitmap()
{
      return m_pplugin_icon;
}

wxString nvc_pi::GetCommonName()
{
      return _("NVC");
}


wxString nvc_pi::GetShortDescription()
{
      return _("nv-charts PlugIn for OpenCPN");
}


wxString nvc_pi::GetLongDescription()
{
      return _("NVC PlugIn for OpenCPN\n\
Provides support of nv-charts raster navigation charts.\n\n\
Supported charts must have been installed with \n\
appropriate decryption dll(s) available.\n\
");

}

wxArrayString nvc_pi::GetDynamicChartClassNameArray()
{
      return m_class_name_array;
}


