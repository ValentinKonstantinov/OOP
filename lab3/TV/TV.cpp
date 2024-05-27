#ifndef CTVSET_H
#define CTVSET_H

#include <string>
#include <map>
#include <vector>

class CTVSet
{
public:
    CTVSet();

    void TurnOn();
    void TurnOff();
    bool SelectChannel(int channel);
    bool SelectChannel(const std::string& channelName);
    bool SelectPreviousChannel();

    void SetChannelName(int channel, const std::string& name);
    void DeleteChannelName(const std::string& name);
    std::string GetChannelName(int channel) const;
    int GetChannelByName(const std::string& name) const;

    void Info() const;

private:
    bool IsValidChannel(int channel) const;
    void AddChannelNameMapping(int channel, const std::string& name);
    void RemoveChannelNameMapping(int channel);

    bool m_isOn;
    int m_currentChannel;
    int m_previousChannel;
    std::map<int, std::string> m_channelNames;
};

#endif // CTVSET_H

CTVSet::CTVSet()
    : m_isOn(false)
    , m_currentChannel(0)
    , m_previousChannel(0)
{
}

void CTVSet::TurnOn()
{
    m_isOn = true;
    if (m_currentChannel == 0)
    {
        m_currentChannel = 1;
    }
    std::cout << "TV is turned on" << std::endl;
}

void CTVSet::TurnOff()
{
    m_isOn = false;
    std::cout << "TV is turned off" << std::endl;
}

bool CTVSet::SelectChannel(int channel)
{
    if (IsValidChannel(channel) && m_isOn)
    {
        m_previousChannel = m_currentChannel;
        m_currentChannel = channel;
        std::cout << "Channel " << channel << " selected" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Invalid channel or TV is turned off" << std::endl;
        return false;
    }
}

bool CTVSet::SelectChannel(const std::string& channelName)
{
    if (m_isOn)
    {
        int channel = GetChannelByName(channelName);
        if (channel != 0)
        {
            return SelectChannel(channel);
        }
    }
    std::cout << "Invalid channel name or TV is turned off" << std::endl;
    return false;
}

bool CTVSet::SelectPreviousChannel()
{
    if (m_isOn)
    {
        if (m_previousChannel != 0)
        {
            return SelectChannel(m_previousChannel);
        }
        else
        {
            std::cout << "No previous channel selected" << std::endl;
            return false;
        }
    }
    std::cout << "TV is turned off" << std::endl;
    return false;
}

void CTVSet::SetChannelName(int channel, const std::string& name)
{
    if (IsValidChannel(channel) && m_isOn)
    {
        RemoveChannelNameMapping(channel);
        AddChannelNameMapping(channel, name);
        std::cout << "Channel " << channel << " is now named \"" << name << "\"" << std::endl;
    }
    else
    {
        std::cout << "Invalid channel or TV is turned off" << std::endl;
    }
}

void CTVSet::DeleteChannelName(const std::string& name)
{
    if (m_isOn)
    {
        auto it = std::find_if(m_channelNames.begin(), m_channelNames.end(), [&](const auto& pair) {
            return pair.second == name;
            });
        if (it != m_channelNames.end())
        {
            int channel = it->first;
            RemoveChannelNameMapping(channel);
            std::cout << "Channel " << channel << " name \"" << name << "\" removed" << std::endl;
        }
        else
        {
            std::cout << "Channel name \"" << name << "\" not found" << std::endl;
        }
    }
    else
    {
        std::cout << "TV is turned off" << std::endl;
    }
}

std::string CTVSet::GetChannelName(int channel) const
{
    auto it = m_channelNames.find(channel);
    if (it != m_channelNames.end())
    {
        return it->second;
    }
    else
    {
        return "";
    }
}

int CTVSet::GetChannelByName(const std::string& name) const
{
    auto it = std::find_if(m_channelNames.begin(), m_channelNames.end(), [&](const auto& pair) {
        return pair.second == name;
        });
    if (it != m_channelNames.end())
    {
        return it->first;
    }
    else
    {
        return 0;
    }
}

void CTVSet::Info() const
{
    std::cout << "TV is " << (m_isOn ? "on" : "off") << std::endl;
    std::cout << "Current channel: " << m_currentChannel << std::endl;
    if (m_isOn)
    {
        std::cout << "Previous channel: " << m_previousChannel << std::endl;
    }
    std::cout << "Channel names:" << std::endl;
    std::vector<std::pair<int, std::string>> sortedNames(m_channelNames.begin(), m_channelNames.end());
    std::sort(sortedNames.begin(), sortedNames.end());
    for (const auto& pair : sortedNames)
    {
        std::cout << pair.first << " - " << pair.second << std::endl;
    }
}

bool CTVSet::IsValidChannel(int channel) const
{
    return channel >= 1 && channel <= 99;
}

void CTVSet::AddChannelNameMapping(int channel, const std::string& name)
{
    m_channelNames[channel] = name;
}

void CTVSet::RemoveChannelNameMapping(int channel)
{
    m_channelNames.erase(channel);
}