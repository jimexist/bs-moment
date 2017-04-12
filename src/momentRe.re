/* duration */
module Duration = {
  type t;
  external humanize : t => string = "" [@@bs.send];
  external milliseconds : t => int = "" [@@bs.send];
  external asMilliseconds : t => float = "" [@@bs.send];
  external seconds : t => int = "" [@@bs.send];
  external asSeconds : t => float = "" [@@bs.send];
  external minutes : t => int = "" [@@bs.send];
  external asMinutes : t => float = "" [@@bs.send];
  external hours : t => int = "" [@@bs.send];
  external asHours : t => float = "" [@@bs.send];
  external days : t => int = "" [@@bs.send];
  external asDays : t => float = "" [@@bs.send];
  external weeks : t => int = "" [@@bs.send];
  external asWeeks : t => float = "" [@@bs.send];
  external months : t => int = "" [@@bs.send];
  external asMonths : t => float = "" [@@bs.send];
  external years : t => int = "" [@@bs.send];
  external asYears : t => float = "" [@@bs.send];
  external toJSON : t => string = "" [@@bs.send];
  external asUnitOfTime :
    [
      | `years
      | `quarters
      | `months
      | `weeks
      | `days
      | `hours
      | `minutes
      | `seconds
      | `milliseconds
    ]
    [@bs.string] =>
    float =
    "as" [@@bs.send.pipe : t];
};

external duration :
  int =>
  [ | `years | `quarters | `months | `weeks | `days | `hours | `minutes | `seconds | `milliseconds]
  [@bs.string] =>
  Duration.t =
  "" [@@bs.module "moment"];

external duration_millis : int => Duration.t = "duration" [@@bs.module "moment"];

external duration_format : string => Duration.t = "duration" [@@bs.module "moment"];

module Moment = {
  type t;
  external clone : t = "" [@@bs.send.pipe : t];
  external mutableAdd : t => Duration.t => unit = "add" [@@bs.send];
  let add ::duration moment => {
    let clone = clone moment;
    mutableAdd clone duration;
    clone
  };
  external mutableSubtract : t => Duration.t => unit = "subtract" [@@bs.send];
  let subtract ::duration moment => {
    let clone = clone moment;
    mutableSubtract clone duration;
    clone
  };
  external mutableStartOf :
    t =>
    [ | `year | `quarter | `month | `week | `day | `hour | `minute | `second | `millisecond]
    [@bs.string] =>
    unit =
    "startOf" [@@bs.send];
  let startOf timeUnit moment => {
    let clone = clone moment;
    mutableStartOf clone timeUnit;
    clone
  };
  external mutableEndOf :
    t =>
    [ | `year | `quarter | `month | `week | `day | `hour | `minute | `second | `millisecond]
    [@bs.string] =>
    unit =
    "endOf" [@@bs.send];
  let endOf timeUnit moment => {
    let clone = clone moment;
    mutableEndOf clone timeUnit;
    clone
  };
  external get :
    [ | `year | `quarter | `month | `week | `day | `hour | `minute | `second | `millisecond]
    [@bs.string] =>
    int =
    "" [@@bs.send.pipe : t];
  external millisecond : int = "" [@@bs.send.pipe : t];
  external second : int = "" [@@bs.send.pipe : t];
  external minute : int = "" [@@bs.send.pipe : t];
  external hour : int = "" [@@bs.send.pipe : t];
  external day : int = "" [@@bs.send.pipe : t];
  external week : int = "" [@@bs.send.pipe : t];
  external month : int = "" [@@bs.send.pipe : t];
  external year : int = "" [@@bs.send.pipe : t];
  external isValid : t => bool = "" [@@bs.send];
  external isBefore : t => t => bool = "" [@@bs.send];
  external isAfter : t => t => bool = "" [@@bs.send];
  external isSame : t => t => bool = "" [@@bs.send];
  external isSameOrBefore : t => t => bool = "" [@@bs.send];
  external isSameOrAfter : t => t => bool = "" [@@bs.send];
  external isBetween : t => t => t => bool = "" [@@bs.send];
  external isDST : t => bool = "" [@@bs.send];
  external isLeapYear : t => bool = "" [@@bs.send];
  /* display */
  external format : string => string = "" [@@bs.send.pipe : t];
  external defaultFormat : string = "format" [@@bs.send.pipe : t];
  external fromNow : t => withoutSuffix::option bool => string = "" [@@bs.send];
  external fromMomemnt : t => other::t => format::option string => string = "from" [@@bs.send];
  external toNow : t => withoutSuffix::option bool => string = "" [@@bs.send];
  external toMoment : t => other::t => format::string => string = "to" [@@bs.send];
  external valueOf : t => float = "" [@@bs.send];
  external daysInMonth : t => int = "" [@@bs.send];
  external toJSON : t => string = "" [@@bs.send];
};

/* parse */
external moment_now : unit => Moment.t = "moment" [@@bs.module];

external moment_default_format : string => Moment.t = "moment" [@@bs.module];

external moment_with_format : string => string => Moment.t = "moment" [@@bs.module];

external moment_with_formats : string => list string => Moment.t = "moment" [@@bs.module];

external moment_with_timestamp : int => Moment.t = "moment" [@@bs.module];

external moment_with_components : list int => Moment.t = "moment" [@@bs.module];

let moment ::format=? value =>
  switch format {
  | Some f => moment_with_format value f
  | None => moment_default_format value
  };
