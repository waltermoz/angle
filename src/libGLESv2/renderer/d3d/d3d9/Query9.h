//
// Copyright (c) 2013 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// Query9.h: Defines the rx::Query9 class which implements rx::QueryImpl.

#ifndef LIBGLESV2_RENDERER_QUERY9_H_
#define LIBGLESV2_RENDERER_QUERY9_H_

#include "libGLESv2/renderer/QueryImpl.h"

namespace rx
{
class Renderer9;

class Query9 : public QueryImpl
{
  public:
    Query9(rx::Renderer9 *renderer, GLenum type);
    virtual ~Query9();

    virtual bool begin();
    virtual void end();
    virtual GLuint getResult();
    virtual GLboolean isResultAvailable();

  private:
    DISALLOW_COPY_AND_ASSIGN(Query9);

    GLboolean testQuery();

    GLuint mResult;
    GLboolean mStatus;

    rx::Renderer9 *mRenderer;
    IDirect3DQuery9 *mQuery;
};

}

#endif // LIBGLESV2_RENDERER_QUERY9_H_
