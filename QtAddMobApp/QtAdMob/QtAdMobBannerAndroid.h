#ifndef QTADMOBBANNER_H
#define QTADMOBBANNER_H

#include "IQtAdMobBanner.h"

#if (__ANDROID_API__ >= 9)

class QAndroidJniObject;

class QtAdMobBannerAndroid : public IQtAdMobBanner
{
public:
    QtAdMobBannerAndroid();
    virtual ~QtAdMobBannerAndroid();

    virtual void Initialize();
    virtual void Shutdown();

    virtual void SetAdUnitId(const QString& unitId);
    virtual void SetAdSize(BannerSize size);
    virtual void SetPosition(const QPoint& position);
    virtual QSize GetDimensions();
    virtual bool IsShowed() const;
    virtual bool IsLoaded() const;
    virtual void ShowAd();
    virtual void HideAd();

    virtual void AddTestDevice(const QString& hashedDeviceId);

private:
    bool IsValid() const;

private:
    QAndroidJniObject* m_Activity;
};

#endif // __ANDROID_API__

#endif // QTADMOBBANNER_H