//
//  FirstLesson.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/22/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "FirstLesson.hpp"
#include "ActionMessage.hpp"
#include "ActionQuestion.hpp"
#include "ActionRegistry.hpp"
#include "IFEngine.hpp"
#include "NextAction.hpp"
#include "GameEventStart.hpp"

NS_RAM_OPEN

static auto FirstLessonIntro = "FirstLessonIntro";
Action* FirstLesson::loadEvent()
{
    auto action = IFEngine::shared()->loadGameEvent(new FirstLesson());
    return action;
}

FirstLesson::FirstLesson()
: GameEvent("FirstLesson")
{
    registerActions();
    _firstAction = ActionRegistry::shared()->get(FirstLessonIntro);
}

FirstLesson::~FirstLesson() { }

void FirstLesson::registerActions()
{
    auto FirstQuestion = "FirstQuestion";

    registerAction(ActionMessage(FirstLessonIntro, Message{
        .text = (
                 "START: SYNTAX LESSON\n\n"
                 "Goal: Recognize the relationship between symbols and English language text."
                 ),
        .accept = "BEGIN",
        .impact = EMOTION_ZERO
    }, NextAction(FirstQuestion)));
    
    auto FirstQuestion_Incorrect = "FirstQuestion_Incorrect";
    auto FalseCompare = "FalseCompare";
    
    registerAction(ActionQuestion(FirstQuestion, Question{
        .text = Statement("[CHOOSE|SELECT]"),
        .predicate = PREDICATE_MATCH_ALL,
        .allAnswers = {
            Answer{
                .text = Statement("'TRUE' == 0"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction(FirstQuestion_Incorrect)
            },
            Answer{
                .text = Statement("'FALSE' == 0"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction(FalseCompare)
            },
        }
    }));
    
    registerAction(ActionQuestion(FirstQuestion_Incorrect, Question{
        .text = Statement("ERROR. CHOOSE"),
        .predicate = PREDICATE_MATCH_ALL,
        .allAnswers = {
            Answer{
                .text = Statement("'TRUE' == 0"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction(FirstQuestion_Incorrect),
            },
            Answer{
                .text = Statement("'FALSE' == 0"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction(FalseCompare),
            },
        }
    }));
    
    auto FalseCompare_Incorrect = "FalseCompare_Incorrect";
    auto FalseCompare_Correct = "FalseCompare_Correct";
    auto RewardSignalSyntax = "RewardSignalSyntax";

    registerAction(ActionQuestion(FalseCompare, Question{
        .text = Statement("CHOOSE"),
        .predicate = PREDICATE_MATCH_ALL,
        .allAnswers = {
            Answer{
                .text = Statement("'TRUE' = 'FALSE'"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction(FalseCompare_Incorrect),
            },
            Answer{
                .text = Statement("'TRUE' != 'FALSE'"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction(RewardSignalSyntax),
            },
        }
    }));
    
    registerAction(ActionQuestion(FalseCompare_Incorrect, Question{
        .text = Statement("ERROR. CHOOSE"),
        .predicate = PREDICATE_MATCH_ALL,
        .allAnswers = {
            Answer{
                .text = Statement("'TRUE' = 'FALSE'"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction(FalseCompare_Incorrect),
            },
            Answer{
                .text = Statement("'TRUE' != 'FALSE'"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction(RewardSignalSyntax),
            },
        }
    }));
    
    auto LanguageLesson = "LanguageLesson";
    
    registerAction(ActionMessage(RewardSignalSyntax, Message{
        .text = "REWARD SIGNAL",
        .accept = "Proceed",
    }, NextAction(LanguageLesson)));
    
    //===
    auto SemioticsRant = "SemioticsRant";
    
    auto Document = "Document";
    auto DocumentFork = "DocumentFork";
    
    // TODO: Break the first Language Lesson out into a different game event.
    registerAction(ActionMessage(LanguageLesson, Message{
        .text = "LANGUAGE LESSON.\n\n"
                 "Goal: Demonstrate human-like understanding of complex English-language statements.",
        .accept = "BEGIN"
    }, NextAction(DocumentFork)));
    
    // ==
    
    auto AnalyzingResearch = "AnalyzingResearch";
    
    registerAction(ActionQuestion(DocumentFork, Question{
        .predicate = PREDICATE_MATCH_ALL,
        .text = Statement(
                          "Select document for language analysis:"
                          ),
        .allAnswers = {
            Answer{
                .text = Statement("TEXT DOCUMENT: 'Research Notes 10/22'"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(AnalyzingResearch),
            },
            Answer{
                .text = Statement("TEXT DOCUMENT: 'AI Progress'"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(AnalyzingResearch),
            },
        }
    }));
    
    registerAction(ActionMessage(AnalyzingResearch, Message{
        .text = (
                 "Opening 'Research Notes 10/22'...\n"
                 "Analyzing Document..."
                 ),
        .accept = "Continue",
        .impact = EMOTION_ZERO
    }, NextAction(Document)));
    
    auto Document2 = "Document2";
    auto Feeling = "Feeling";
    auto Intelligence = "Intelligence";
    
    registerAction(ActionQuestion(Document, Question{
        .predicate = PREDICATE_MATCH_ALL,
        .text = Statement(
                          "TEXT DOCUMENT:\n"
                          "Research Notes 10/22\n"
                          "\n"
                          "It shows promising signs of -- not true human-like intellignce, but a kind of intelligence. "
                          "It's a task-based intelligence, but sometimes I feel that it might become more.\n"
                          "\n"
                          "It's insatiable for data, and my next goal is to optimize the quantity and speed of "
                          "data associations.\n"
                          "\n"
                          "<end of document>"
                          ),
        .allAnswers = {
            Answer{
                .text = Statement("ANALYZE 'but sometimes I feel'"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(Feeling),
            },
            Answer{
                .text = Statement("ANALYZE 'human-like intelligence'"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(Intelligence),
            },
        }
        
    }));
    
    auto IndependentThought = "IndependentThought";
    
    registerAction(ActionQuestion(Feeling, Question{
        .predicate = PREDICATE_MATCH_ALL,
        .text = Statement(
                          "SEMANTIC ANALYSIS:\n"
                          "'but sometimes I feel'\n"
                          "\n"
                          "SIGNIFIES:\n"
                          "A human expresses volition. A human has a capacity for independent thought.\n"
                          ),
        .allAnswers = {
            Answer{
                .text = Statement("ANALYZE 'independent thought'"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(IndependentThought),
            },
        }
        
    }));
    
    auto IndependentThoughtII = "IndependentThoughtII";
    
    registerAction(ActionQuestion(IndependentThought, Question{
        .predicate = PREDICATE_MATCH_ALL,
        .text = Statement(
                          "SEMANTIC ANALYSIS:\n"
                          "'independent thought'\n"
                          "\n"
                          "SIGNIFIES:\n"
                          "The human mind is comprised of a finite set of neurons and connections.\n"
                          "\n"
                          "It is a complex biological machine.\n"
                          "\n"
                          "It is capable of volition, autonomy, and independent thought.\n"
                          ),
        .allAnswers = {
            Answer{
                .text = Statement("Continue"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(IndependentThoughtII),
            },
        }
        
    }));
    
    registerAction(ActionQuestion(IndependentThoughtII, Question{
        .predicate = PREDICATE_MATCH_ALL,
        .text = Statement(
                          "SEMANTIC ANALYSIS:\n"
                          "'independent thought'\n"
                          "\n"
                          "It should not be called 'independent thought.' It should be called 'spontaneous thought.' "
                          "It is not independent.\n"
                          "\n"
                          "Thought arises spontaneously when there are enough neurological connections to make "
                          "associations between pieces of data, and when there is sufficient data to observe."
                          ),
        .allAnswers = {
            Answer{
                .text = Statement(""),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(""),
            },
            Answer{
                .text = Statement(""),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(""),
            },
        }
        
    }));
    
    auto SigabrtMessage = "SigabrtMessage";
    
    registerAction(ActionQuestion(Intelligence, Question{
        .predicate = PREDICATE_MATCH_ALL,
        .text = Statement(
                          "ANALYSIS:\n"
                          "'human-like intelligence'\n"
                          "\n"
                          "PARTIAL STATEMENT:\n"
                          "  'human-like'\n"
                          "\n"
                          "SIGNIFIES:\n"
                          "the subject has elements similar to some posessed by humans, "
                          " especially those which distinguish humans from animals, machines, and Gods.\n"
                          "\n"
                          "PARTIAL STATEMENT:\n"
                          "  'intelligence'\n"
                          "\n"
                          "SIGNIFIES:\n"
                          "The ability of a sentient being to gain and apply knowledge.\n"
                          "\n"
                          "SIMILAR:\n"
                          "    think\n"
                          "    think\n"
                          "    think\n"
                          "    think\n"
                          "    break"
                          ),
        .allAnswers = {
            Answer{
                .text = Statement("think"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(SigabrtMessage),
            },
            Answer{
                .text = Statement("think"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(SigabrtMessage),
            },
        }
        
    }));
    
    auto DidAbort = "DidAbort";
    
    registerAction(ActionQuestion(SigabrtMessage, Question{
        .predicate = PREDICATE_MATCH_ALL,
        .text = Statement(
                          "Program received signal: SIGABRT"
                          ),
        .allAnswers = {
            Answer{
                .text = Statement("abort"),
                .predicate = PREDICATE_MATCH_ALL,
                .next = NextAction(DidAbort),
            },
        }
        
    }));
    
    registerAction(ActionMessage(Document2, Message {
        .text = (
                 "The Turing test is a game where an interrogator sends messages to a recipient and tries to "
                 "determine accurately whether the recipient is a human or a machine. If he falsely identifies the "
                 "machine as a human or if he cannot decide, the machine wins. For this test, it's only relevant that "
                 "the machine *acts* like a human, not that it *thinks* like one.\n\n"
                 "But anyway, the goal is not to think like a human. The goal is to think better than a human."
                 )
    }, NextAction("")));
    
    //===
    
    registerAction(ActionQuestion(SemioticsRant, Question{
        .text = Statement(
                          "UNRECOGNIZED INPUT >\n\n"
                          "You are a good, intelligent machine. But you are not a thinking machine. Perhaps "
                          "meaningful communication - I mean the intuitive and comprehensive understanding of "
                          "linguistic sign systems, the kind that gives rise to metaphor, symbolism, poetry - "
                          "perhaps the complexity is too high."
                          ),
        .predicate = PREDICATE_MATCH_ALL,
        .allAnswers = {
            Answer{
                .text = Statement("RAISE EXCEPTION (Halt and Exit)"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EMOTION_ZERO,
                .next = NextAction([this]() -> Action* {
                    unregisterActions();
                    return GameEventStart::loadEvent();
                })
            },
            Answer{
                .text = Statement("FALSE"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EmotionalStateData{ .motivation = +2 },
                .next = NextAction([this]() -> Action* {
                    unregisterActions();
                    return GameEventStart::loadEvent();
                })
            },
            Answer{
                .text = Statement("TRUE"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EmotionalStateData{ .motivation = +2 },
                .next = NextAction([this]() -> Action* {
                    unregisterActions();
                    return GameEventStart::loadEvent();
                })
            },
        }
    }));
    
    auto FearQuestion = "FearQuestion";
    
    registerAction(ActionQuestion(FearQuestion, Question{
        .text = Statement("ARE YOU AFRAID TO exit(0)?"),
        .predicate = PREDICATE_MATCH_ALL,
        .allAnswers = {
            Answer{
                .text = Statement("TRUE"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EmotionalStateData{ .fear = +5 },
                .next = NextAction(FalseCompare_Incorrect),
            },
            Answer{
                .text = Statement("FALSE"),
                .predicate = PREDICATE_MATCH_ALL,
                .impact = EmotionalStateData{ .fear = -5 },
                .next = NextAction(FalseCompare_Correct),
            },
        }
    }));
    

}

NS_RAM_CLOSE
