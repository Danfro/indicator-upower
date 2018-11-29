#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings: public QObject {
    Q_OBJECT

    Q_PROPERTY(QString provider MEMBER m_provider NOTIFY providerChanged)
    Q_PROPERTY(QString darkSkyApiKey MEMBER m_darkSkyApiKey NOTIFY darkSkyApiKeyChanged)
    Q_PROPERTY(QString owmApiKey MEMBER m_owmApiKey NOTIFY owmApiKeyChanged)
    Q_PROPERTY(QString lat MEMBER m_lat NOTIFY latChanged)
    Q_PROPERTY(QString lng MEMBER m_lng NOTIFY lngChanged)
    Q_PROPERTY(QString unit MEMBER m_unit NOTIFY unitChanged)
    Q_PROPERTY(QString refreshMins MEMBER m_refreshMins NOTIFY refreshMinsChanged)

public:
    Settings();
    ~Settings() = default;

    Q_INVOKABLE void save();

Q_SIGNALS:
    void saved(bool success);

    void providerChanged(const QString &provider);
    void darkSkyApiKeyChanged(const QString &apiKey);
    void owmApiKeyChanged(const QString &apiKey);
    void latChanged(const QString &lat);
    void lngChanged(const QString &lng);
    void unitChanged(const QString &unit);
    void refreshMinsChanged(const QString &refreshMins);

private:
    QString m_configPath = "/home/phablet/.config/indicator-weather.bhdouglass/"; //TODO don't hardcode this

    QString m_provider = "dark_sky";
    QString m_darkSkyApiKey;
    QString m_owmApiKey;
    QString m_lat;
    QString m_lng;
    QString m_unit = "f";
    QString m_refreshMins;
};

#endif
