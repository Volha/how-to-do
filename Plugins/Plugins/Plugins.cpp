// Plugins.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IPlugin.h"
#include <vector>
#include <algorithm>
#include <memory>

#include "../Plugin1/Plugin1.h"
#include "../Plugin2/Plugin2.h"


typedef std::shared_ptr<IPlugin> IPluginPtr;
typedef std::vector<IPluginPtr> PluginsVector;

PluginsVector LoadPlugins()
{
	PluginsVector plugins;
	plugins.push_back(std::make_shared<Plugin1>()); 
	plugins.push_back(std::make_shared<Plugin2>());
	return plugins;
}

class MediaPlayer 
{
private:
	class Sample
	{
	public:
		Sample()
			:m_data(3)
		{
			
		}

		operator unsigned short()
		{
			return m_data;
		}

		unsigned short GetData() const
		{
			return m_data;
		}

	private:
		unsigned short m_data;
	};

public:
	MediaPlayer()
		: m_plugins(LoadPlugins())
	{
	}
	void Play()
	{
		auto samples = GetSamples();
		std::for_each(samples.begin(), samples.end(), [&](const Sample& singleSample)
		{
			PlaySamples(singleSample);
		});

	}

private:
	std::vector<Sample> GetSamples()
	{
		return std::vector<Sample>(10);
	}

	void PlaySamples(const Sample& sample)
	{
		std::for_each(m_plugins.begin(), m_plugins.end(), [&sample](IPluginPtr plugin)
		{
			plugin->PlaySample(sample.GetData());
		});
	}

private:
	PluginsVector m_plugins;
	std::vector<Sample> m_sample;
};

typedef std::shared_ptr<MediaPlayer> MediaPlayerPtr;

int _tmain(int argc, _TCHAR* argv[])
{
	MediaPlayerPtr player = std::make_shared<MediaPlayer>();
	player->Play();

	return 0;
}

