/* duration */
module Duration = {
  type t;
  [@bs.send] external humanize : t => string = "";
  [@bs.send] external milliseconds : t => int = "";
  [@bs.send] external asMilliseconds : t => float = "";
  [@bs.send] external seconds : t => int = "";
  [@bs.send] external asSeconds : t => float = "";
  [@bs.send] external minutes : t => int = "";
  [@bs.send] external asMinutes : t => float = "";
  [@bs.send] external hours : t => int = "";
  [@bs.send] external asHours : t => float = "";
  [@bs.send] external days : t => int = "";
  [@bs.send] external asDays : t => float = "";
  [@bs.send] external weeks : t => int = "";
  [@bs.send] external asWeeks : t => float = "";
  [@bs.send] external months : t => int = "";
  [@bs.send] external asMonths : t => float = "";
  [@bs.send] external years : t => int = "";
  [@bs.send] external asYears : t => float = "";
  [@bs.send] external toJSON : t => string = "";
  [@bs.send.pipe : t]
  external asUnitOfTime :
    (
    [@bs.string]
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
    ) =>
    float =
    "as";
};

[@bs.module "moment"]
external duration :
  (
    int,
    [@bs.string]
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
  ) =>
  Duration.t =
  "";

[@bs.module "moment"] external durationMillis : int => Duration.t = "duration";

[@bs.module "moment"] external durationFormat : string => Duration.t = "duration";

module Moment = {
  type t;
  [@bs.send.pipe : t] external clone : t = "";
  [@bs.send] external mutableAdd : (t, Duration.t) => unit = "add";
  let add = (~duration, moment) => {
    let clone = clone(moment);
    mutableAdd(clone, duration);
    clone
  };
  [@bs.send] external mutableSubtract : (t, Duration.t) => unit = "subtract";
  let subtract = (~duration, moment) => {
    let clone = clone(moment);
    mutableSubtract(clone, duration);
    clone
  };
  [@bs.send]
  external mutableStartOf :
    (
      t,
      [@bs.string]
      [ | `year | `quarter | `month | `week | `day | `hour | `minute | `second | `millisecond]
    ) =>
    unit =
    "startOf";
  let startOf = (timeUnit, moment) => {
    let clone = clone(moment);
    mutableStartOf(clone, timeUnit);
    clone
  };
  [@bs.send]
  external mutableEndOf :
    (
      t,
      [@bs.string]
      [ | `year | `quarter | `month | `week | `day | `hour | `minute | `second | `millisecond]
    ) =>
    unit =
    "endOf";
  let endOf = (timeUnit, moment) => {
    let clone = clone(moment);
    mutableEndOf(clone, timeUnit);
    clone
  };
  [@bs.send] external mutableSetMillisecond : (t, int) => unit = "millisecond";
  let setMillisecond = (milliseconds, moment) => {
    let clone = clone(moment);
    mutableSetMillisecond(clone, milliseconds);
    clone
  };
  [@bs.send] external mutableSetSecond : (t, int) => unit = "second";
  let setSecond = (seconds, moment) => {
    let clone = clone(moment);
    mutableSetSecond(clone, seconds);
    clone
  };
  [@bs.send] external mutableSetMinute : (t, int) => unit = "minute";
  let setMinute = (minutes, moment) => {
    let clone = clone(moment);
    mutableSetMinute(clone, minutes);
    clone
  };
  [@bs.send] external mutableSetHour : (t, int) => unit = "hour";
  let setHour = (hours, moment) => {
    let clone = clone(moment);
    mutableSetHour(clone, hours);
    clone
  };
  [@bs.send] external mutableSetDate : (t, int) => unit = "date";
  let setDate = (days, moment) => {
    let clone = clone(moment);
    mutableSetDate(clone, days);
    clone
  };
  [@bs.send] external mutableSetMonth : (t, int) => unit = "month";
  let setMonth = (months, moment) => {
    let clone = clone(moment);
    mutableSetMonth(clone, months);
    clone
  };
  [@bs.send] external mutableSetYear : (t, int) => unit = "year";
  let setYear = (years, moment) => {
    let clone = clone(moment);
    mutableSetYear(clone, years);
    clone
  };
  [@bs.send.pipe : t]
  external get :
    (
    [@bs.string]
    [ | `year | `quarter | `month | `week | `day | `hour | `minute | `second | `millisecond]
    ) =>
    int =
    "";
  [@bs.send.pipe : t] external millisecond : int = "";
  [@bs.send.pipe : t] external second : int = "";
  [@bs.send.pipe : t] external minute : int = "";
  [@bs.send.pipe : t] external hour : int = "";
  [@bs.send.pipe : t] external day : int = "";
  [@bs.send.pipe : t] external week : int = "";
  [@bs.send.pipe : t] external month : int = "";
  [@bs.send.pipe : t] external year : int = "";
  [@bs.send.pipe : t] external weekday : int = "";
  [@bs.send] external isValid : t => bool = "";
  [@bs.send] external isBefore : (t, t) => bool = "";
  [@bs.send] external isAfter : (t, t) => bool = "";
  [@bs.send] external isSame : (t, t) => bool = "";
  [@bs.send] external isSameOrBefore : (t, t) => bool = "";
  [@bs.send] external isSameOrAfter : (t, t) => bool = "";
  [@bs.send] external isBetween : (t, t, t) => bool = "";
  [@bs.send] external isDST : t => bool = "";
  [@bs.send] external isLeapYear : t => bool = "";
  /* display */
  [@bs.send.pipe : t] external format : string => string = "";
  [@bs.send.pipe : t] external defaultFormat : string = "format";
  [@bs.send.pipe : t] external utc : string => t = "";
  [@bs.send.pipe : t] external defaultUtc : t = "utc";
  [@bs.send.pipe : t] external locale : string => t = "";
  [@bs.send] external fromNow : (t, ~withoutSuffix: option(bool)) => string = "";
  [@bs.send] external fromMoment : (t, ~other: t, ~format: option(string)) => string = "from";
  [@bs.send] external toNow : (t, ~withoutSuffix: option(bool)) => string = "";
  [@bs.send] external toMoment : (t, ~other: t, ~format: string) => string = "to";
  [@bs.send] external valueOf : t => float = "";
  [@bs.send] external daysInMonth : t => int = "";
  [@bs.send] external toJSON : t => string = "";
  [@bs.send] external toDate : t => Js.Date.t = "";
  [@bs.send] external toUnix : t => int = "unix";
};

/* parse */
[@bs.module] external momentNow : unit => Moment.t = "moment";

[@bs.module] external momentDefaultFormat : string => Moment.t = "moment";

[@bs.module] external momentWithFormat : (string, string) => Moment.t = "moment";

[@bs.module] external momentWithDate : Js.Date.t => Moment.t = "moment";

[@bs.module] external momentWithFormats : (string, list(string)) => Moment.t = "moment";

[@bs.module] external momentWithTimestampMS : float => Moment.t = "moment";

[@bs.module] external momentWithComponents : list(int) => Moment.t = "moment";

let momentWithUnix = (timestamp: int) => momentWithTimestampMS(float_of_int(timestamp) *. 1000.0);

[@bs.send]
external diff :
  (
    Moment.t,
    Moment.t,
    [@bs.string]
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
  ) =>
  float =
  "";

let moment = (~format=?, value) =>
  switch format {
  | Some(f) => momentWithFormats(value, f)
  | None => momentDefaultFormat(value)
  };
