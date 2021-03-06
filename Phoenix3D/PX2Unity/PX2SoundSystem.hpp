// PX2SoundSystem.hpp

#ifndef PX2SOUNDSYSTEM_HPP
#define PX2SOUNDSYSTEM_HPP

#include "PX2Sound.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2FString.hpp"

namespace PX2
{

	struct SoundSystemInitInfo
	{
		SoundSystemInitInfo();

		int MaxChannels;
		float DopplerScale;
		float DistanceFactor;
		float RolloffScale;
	};

	struct SoundCreateInfo3D
	{
		SoundCreateInfo3D();

		float MinDistance;
		float MaxDistance;
		float Volume;
		APoint Position;
		AVector Velocity;
		bool IsLoop;
	};

	class SoundSystem : public Singleton<SoundSystem>
	{
	public:
		virtual ~SoundSystem();

		enum SystemType
		{
			ST_NULL,
			ST_FMOD,
			ST_MAX_TYPE
		};
		SystemType GetSystemType() const;

		static SoundSystem *Create(SystemType type,
			const SoundSystemInitInfo &initInfo);

		virtual void Clear();

		virtual void Update(double appSeconds, double elapsedSeconds);

		// listen
		/* 不关心参数可设置为0*/
		virtual void SetListener(const APoint *position,
			const AVector *velocity, const AVector *forward,
			const AVector *up);
		const APoint &GetListenerPos() const;

		/// 在指定通道播放音乐
		/**
		* channel : 播放音乐的通道（0-3）
		* filename : 音乐文件名，为0表示停止当前音乐
		* isLoop : 是否循环播放
		* fadeSeconds : 淡入淡出时间，为0.0f表示立即最大音量播放
		*/
		virtual void PlayMusic(int channel, const char *filename,
			bool isLoop, float fadeSeconds, float volume = 1.0f) = 0;
		virtual void SetMusicVolume(int channel, float volume) = 0;
		virtual void EnableMusic(bool enable);
		bool IsMusicEnable() const;

		// sound 
		virtual bool PlaySound2DControl(const char *filename,
			float volume, bool isLoop, Sound *&sound);
		virtual bool PlaySound3DControl(const char *filename,
			const SoundCreateInfo3D &createInfo, Sound *&sound);
		virtual void LoadSound(const char *filename);
		virtual void UnloadSound(const char *filename);
		virtual void EnableSounds(bool enable);
		bool IsSoundEnable() const;

		// same time
		void SetMaxNumPlaySameTime(const char *filename, int num);
		int GetMaxNumPlaySameTime(const char *filename) const;
		void SetPlaySameTimeRange(const char *filename, float time);
		float GetPlaySameTimeRange(const char *filename) const;

	public_internal:
		void _MinusNumPlaySameTime(const char *filename);

	protected:
		SoundSystem();
		SoundSystem(SystemType type);

		bool _CanPlaySameTime(const char *filename, float playTime);
		int _GetNumPlaySameTime(const char *filename);
		void _ResetNumPlaySameTime(const char *filename);

		SystemType mSystemType;
		APoint mListenPos;

		int mDefaultMaxNumPlaySameTime;
		float mDefaultSameTimeRange;

		bool mIsMusicEnable;
		bool mIsSoundEnable;

		struct PlaySameTimeObj
		{
			PlaySameTimeObj();

			int MaxNum;
			int CurNum;
			float SameTimeRange;
			float CurTiming;
		};
		std::map<FString, PlaySameTimeObj> mPlaySameTimeObjMap;
	};

#include "PX2SoundSystem.inl"

#define PX2_SS SoundSystem::GetSingleton()


}

#endif