#ifndef GANG_GANG_DECODER_HH
#define GANG_GANG_DECODER_HH

#include "webrtc/base/basictypes.h"
#include "webrtc/base/constructormagic.h"
#include "talk/media/base/videocapturer.h"
#include "gang_decoder.h"
#include "gang_decoder_impl.h"

namespace gang {

// need be shared_ptr
class VideoFrameObserver {
public:
	// signal data
	virtual void OnVideoFrame(uint8* data, uint32 size) = 0;
	virtual void OnBestFormat(int width, int height, int fps) = 0;
protected:
	~VideoFrameObserver() {
	}
};

// need be shared_ptr
class AudioFrameObserver {
public:
	// signal data
	virtual void OnAudioFrame(uint8* data, uint32 size) = 0;
protected:
	~AudioFrameObserver() {
	}
};

class GangDecoder {
public:
	explicit GangDecoder(const char* url,
			VideoFrameObserver* video_frame_observer = NULL,
			AudioFrameObserver* audio_frame_observer = NULL);
	~GangDecoder();

	bool Init();
	bool Start();
	void Stop();

	void NextFrameLoop();

	void SetVideoFrameObserver(VideoFrameObserver* video_frame_observer_);
	void SetAudioFrameObserver(AudioFrameObserver* audio_frame_observer_);
private:
	VideoFrameObserver* video_frame_observer_;
	AudioFrameObserver* audio_frame_observer_;
	gang_decoder* decoder_;

	DISALLOW_COPY_AND_ASSIGN(GangDecoder);
};

}  // namespace gang

#endif // GANG_GANG_DECODER_HH
