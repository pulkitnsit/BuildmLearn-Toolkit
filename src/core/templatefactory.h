/*
  Copyright (c) 2012, BuildmLearn Contributors listed at http://buildmlearn.org/people/
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the name of the BuildmLearn nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef TEMPLATEFACTORY_H
#define TEMPLATEFACTORY_H

#include <QObject>


class TemplateEntryPoint;
class TemplateCore;

class TemplateFactory : public QObject {
    Q_OBJECT

  public:
    // Constructors and destructors.
    explicit TemplateFactory(QObject *parent = 0);
    virtual ~TemplateFactory();

    /// \brief Access to available templates.
    /// \see TemplateEntryPoint
    /// \return Method returns list of available templates. Templates
    /// are not sorted in any particular order.
    QList<TemplateEntryPoint*> availableTemplates() {
      return m_availableTemplates;
    }

  public slots:
    void startNewProject(TemplateEntryPoint *entry_point);
    void loadProject(const QString &bundle_file_name);

  private:
    void setupTemplates();

    QList<TemplateEntryPoint*> m_availableTemplates;
};

#endif // TEMPLATEFACTORY_H